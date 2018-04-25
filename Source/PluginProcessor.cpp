/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Synth_polyphoniqueAudioProcessor::Synth_polyphoniqueAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),

tree(*this, nullptr)
#endif

{
    NormalisableRange<float> attackParam(0.1f, 10000.0f);
    NormalisableRange<float> decayParam(1.0f, 5000.0f);
    NormalisableRange<float> sustainParam(0.0f, 1.0f);
    NormalisableRange<float> releaseParam(0.0f, 10000.0f);
    
    tree.createAndAddParameter("attack", "Attack", "Attack", attackParam, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("decay", "Decay", "Decay", decayParam, 1.0f, nullptr, nullptr);
    tree.createAndAddParameter("sustain", "Sustain", "Sustain", sustainParam, 0.8f, nullptr, nullptr);
    tree.createAndAddParameter("release", "Release", "Release", releaseParam, 0.1f, nullptr, nullptr);

    NormalisableRange<float> waveformParam(0, 7);
    tree.createAndAddParameter("waveform", "Waveform", "waveform", waveformParam, 0, nullptr, nullptr);
    
    NormalisableRange<float> waveform2Param(0, 7);
    tree.createAndAddParameter("waveform2", "Waveform2", "waveform2", waveform2Param, 0, nullptr, nullptr);
    
    NormalisableRange<float> mixerParam(0.0f, 1.0f);
    tree.createAndAddParameter("mixer", "Mixer", "mixer", mixerParam, 0.5f, nullptr, nullptr);
    
    NormalisableRange<float> filterTypeVal(0, 2);
    tree.createAndAddParameter("filterType", "FilterType", "filterType", filterTypeVal, 0, nullptr, nullptr);
    
    NormalisableRange<float> filtVal(20.0f, 10000.0f);
    tree.createAndAddParameter("filterCutoff", "FilterCutoff", "filterCutoff", filtVal, 5000.0f, nullptr, nullptr);
    
    NormalisableRange<float> resVal(1.0f, 5.0f);
    tree.createAndAddParameter("filterResonance", "FilterResonance", "filterResonance", resVal, 1.0f, nullptr, nullptr);
    
    NormalisableRange<float> LFOTypeVal(0,6);
    tree.createAndAddParameter("oscillator", "Oscillator", "oscillator", LFOTypeVal, 0, nullptr, nullptr);
    
    NormalisableRange<float> parametreTypeVal(0,1);
    tree.createAndAddParameter("assigned parameter", "Assigned Parameter", "assigned parameter", parametreTypeVal, 0, nullptr, nullptr);

    NormalisableRange<float> rateVal(0.0f, 250.0f);
    tree.createAndAddParameter("rate", "Rate", "rate", rateVal, 0.0f, nullptr, nullptr);

    NormalisableRange<float> amountVal(0.0f, 1.0f);
    tree.createAndAddParameter("amount", "Amount", "amount", amountVal, 0.0f, nullptr, nullptr);
    
    //where we clear the old voices and add our new voices to make the synth polyphonique

    mySynth.clearVoices();//where we clear our voices for our global synth object
    
    for (int i =0; i<5; i++){
        mySynth.addVoice(new SynthVoice);//we add our 5 voices
    }
    
    mySynth.clearSounds();//clear the sound
    
    mySynth.addSound(new SynthSound);//now we add the new synth sound chosen
}

Synth_polyphoniqueAudioProcessor::~Synth_polyphoniqueAudioProcessor()
{
}

//==============================================================================
const String Synth_polyphoniqueAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Synth_polyphoniqueAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Synth_polyphoniqueAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Synth_polyphoniqueAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Synth_polyphoniqueAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Synth_polyphoniqueAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Synth_polyphoniqueAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Synth_polyphoniqueAudioProcessor::setCurrentProgram (int index)
{
}

const String Synth_polyphoniqueAudioProcessor::getProgramName (int index)
{
    return {};
}

void Synth_polyphoniqueAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Synth_polyphoniqueAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);//so we dont have a sample rate thats constantly changing
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Synth_polyphoniqueAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Synth_polyphoniqueAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Synth_polyphoniqueAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for(int i =0; i<mySynth.getNumVoices(); ++i){
        if((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i)))){
            myVoice->getParam(tree.getRawParameterValue("attack"), tree.getRawParameterValue("decay"), tree.getRawParameterValue("sustain"),tree.getRawParameterValue("release"));
            myVoice->getOscType(tree.getRawParameterValue("waveform"));
            myVoice->getOsc2Type(tree.getRawParameterValue("waveform2"));
            myVoice->mixerOsc(tree.getRawParameterValue("mixer"));
            myVoice->getFilterType(tree.getRawParameterValue("filterType"), tree.getRawParameterValue("filterCutoff"), tree.getRawParameterValue("filterResonance"));
            myVoice->getLFO(tree.getRawParameterValue("oscillator"), tree.getRawParameterValue("assigned parameter"), tree.getRawParameterValue("rate"), tree.getRawParameterValue("amount"));
        }
    }
    
    buffer.clear();//we clear the other sounds
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool Synth_polyphoniqueAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Synth_polyphoniqueAudioProcessor::createEditor()
{
    return new Synth_polyphoniqueAudioProcessorEditor (*this);
}

//==============================================================================
void Synth_polyphoniqueAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Synth_polyphoniqueAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Synth_polyphoniqueAudioProcessor();
}
