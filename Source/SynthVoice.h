
/*  ==============================================================================

    SynthVoice.h
    Created: 29 Jan 2018 1:51:43pm
    Author:  Jeremy Kaufman

    ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "Maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:

        bool canPlaySound(SynthesiserSound* sound){
            return dynamic_cast<SynthSound*>(sound)!= nullptr;
        }
    
        void getParam(float *attack, float *decay, float *sustain, float *release){
            env1.setAttack(double (*attack));
            env1.setDecay(double(*decay));
            env1.setSustain(double(*sustain));
            env1.setRelease(double (*release));
        }
        double setEnvelope(){
            return env1.adsr(mixerOsc(&panoramisation), env1.trigger);
        }
        void getOscType(float* selection){
            theWave = *selection;
        }
        double setOscType(){
            if(theWave==0)
                return osc1.sinewave(frequency);
            else if(theWave==1)
                return osc1.saw(frequency);
            else if(theWave==2)
                return osc1.square(frequency);
            else if(theWave==3)
                return osc1.triangle(frequency);
            else if(theWave==4)
                return osc1.rect(frequency);
            else if(theWave==5)
                return osc1.phasor(frequency);
            else if(theWave==6)
                return osc1.coswave(frequency);
            else if(theWave==7)
                return osc1.noise();
            else
                return osc1.sinewave(frequency);
        }
        void getOsc2Type(float* selection){
            theWave2 = *selection;
        }
        
        double mixerOsc(float *pan) {
            panoramisation = *pan;
            panL = 1-panoramisation;
            panR = panoramisation;
            mix = (setOscType()*panL+setOsc2Type()*panR)*.707;
            return mix;
        
        }
        double setOsc2Type(){
            if(theWave2==0)
                return osc2.sinewave(frequency);
            else if(theWave2==1)
                return osc2.saw(frequency);
            else if(theWave2==2)
                return osc2.square(frequency);
            else if(theWave2==3)
                return osc2.triangle(frequency);
            else if(theWave2==4)
                return osc2.rect(frequency);
            else if(theWave2==5)
                return osc2.phasor(frequency);
            else if(theWave2==6)
                return osc2.coswave(frequency);
            else if(theWave2==7)
                return osc2.noise();
            else
                return osc2.sinewave(frequency);
        }
    
        void getFilterType(float *select, float *cutoff, float *resonance){
            filterChoice = *select;
            cut = *cutoff;
            res = *resonance;
        }
    
    
        double setFilter(){
            if(parameterChoice==0){
                if(filterChoice==0)
                    return filter1.lores(setEnvelope(), setLFOparam(), res);
                else if(filterChoice==1)
                    return filter1.hires(setEnvelope(), setLFOparam(), res);
                else if(filterChoice==2)
                    return filter1.bandpass(setEnvelope(), setLFOparam(), res);
                else
                    return filter1.lores(setEnvelope(), setLFOparam(), res);
            }
            else if(parameterChoice==1){
                if(filterChoice==0)
                    return filter1.lores(setEnvelope(), cut, setLFOparam());
                else if(filterChoice==1)
                    return filter1.hires(setEnvelope(), cut, setLFOparam());
                else if(filterChoice==2)
                    return filter1.bandpass(setEnvelope(), cut, setLFOparam());
                else
                    return filter1.lores(setEnvelope(), cut, setLFOparam());
            }
            else{//LFO is not affecting the cutoff of resonance in this if statement
                if(filterChoice==0)
                    return filter1.lores(setEnvelope(), cut, res);
                else if(filterChoice==1)
                    return filter1.hires(setEnvelope(), cut, res);
                else if(filterChoice==2)
                    return filter1.bandpass(setEnvelope(), cut, res);
                else
                    return filter1.lores(setEnvelope(), cut, res);
            }
        }
    
    
        void getLFO(float *selection1, float *selection2, float*speed, float*power){
            oscillatorChoice = *selection1;
            parameterChoice = *selection2;
            lfoRate = *speed;
            lfoAmount = *power;
            
        }
        double setOscillatorLFO(){
            if(oscillatorChoice==0)
                return lfoOsc.sinewave(lfoRate);
            else if(oscillatorChoice==1)
                return lfoOsc.saw(lfoRate);
            else if(oscillatorChoice==2)
                return lfoOsc.square(lfoRate);
            else if(oscillatorChoice==3)
                return lfoOsc.triangle(lfoRate);
            else if(oscillatorChoice==4)
                return lfoOsc.rect(lfoRate);
            else if(oscillatorChoice==5)
                return lfoOsc.phasor(lfoRate);
            else if(oscillatorChoice==6)
                return lfoOsc.coswave(lfoRate);
            else
                return lfoOsc.sinewave(lfoRate);
        
        }
    
        double setLFOparam(){
            if(parameterChoice==0)
                return cut+=(lfoAmount*setOscillatorLFO());
            else if(parameterChoice==1)
                return res+=((lfoAmount/20.0)*setOscillatorLFO());
            else 
                return cut+=(lfoAmount*setOscillatorLFO());
        }
    
        void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
            env1.trigger = 1;
            level = velocity;
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);

        }
    
    
        void stopNote(float velocity, bool allowTailOff){
            env1.trigger = 0;
            allowTailOff = false;
            if(velocity ==0)
                clearCurrentNote();
            
        }
        void getVolume(float *selection){
            volumeAmnt = *selection;
    
        }
        double setVolumeparam(){
            level += volumeAmnt;
            return level;
        }
    
        void getTranspose(float *selection){
            transposeAmnt = *selection;

        }
        double setTranspose(){
            
        }
        void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples){
            
            for(int sample = 0; sample<numSamples; ++sample){
                for(int channel=0; channel<outputBuffer.getNumChannels(); ++channel){
                    outputBuffer.addSample(channel, startSample, setFilter()*0.4f);
                }
                
                ++startSample;
            }
         }

        //=============================================
        void pitchWheelMoved(int newPitchWheelValue){
        
        }
        //=============================================
        void controllerMoved(int controllerNumber, int newControllerValue){
        
        }
        //=============================================
        void aftertouchChanged(int newAftertouchValue){
        
        }
        //=============================================
        void channelPressureChanged(int newChannelPressureValue){
        
        }
        //=============================================
        bool isVoiceActive(){
             
        }
        //=============================================
       
private:
        double level;
        double frequency;
        int theWave;
        int theWave2;
        int filterChoice;
        float cut;
        float res;
        float panoramisation;
        double panL;
        double panR;
        double mix;
    
        int oscillatorChoice;
        int parameterChoice;
        float lfoRate;
        float lfoAmount;
    
        float volumeAmnt;
        int transposeAmnt;
    
        maxiOsc osc1;
        maxiOsc osc2;
        maxiOsc lfoOsc;
    
        maxiEnv env1;
        maxiFilter filter1;
};
