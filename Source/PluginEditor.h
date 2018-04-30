/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"
#include "Filter.h"
#include "LFO.h"
#include "Mixer.h"




class Synth_polyphoniqueAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Synth_polyphoniqueAudioProcessorEditor (Synth_polyphoniqueAudioProcessor&);
    ~Synth_polyphoniqueAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Synth_polyphoniqueAudioProcessor& processor;
    
    Oscillator oscGui;
    Envelope envGui;
    Filter filtGui;
    LFO lfoGui;
    
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Synth_polyphoniqueAudioProcessorEditor)
};
