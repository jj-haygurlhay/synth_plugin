/*
  ==============================================================================

    Envelope.h
    Created: 21 Mar 2018 2:12:11pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope    : public Component
{
public:
    Envelope(Synth_polyphoniqueAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
    
private:
    
    Slider attackSlider;
    Slider releaseSlider;
    Slider decaySlider;
    Slider sustainSlider;
    
    AudioProcessorValueTreeState::SliderAttachment* attackTree;
    AudioProcessorValueTreeState::SliderAttachment* decayTree;
    AudioProcessorValueTreeState::SliderAttachment* sustainTree;
    AudioProcessorValueTreeState::SliderAttachment* releaseTree;
    
    Synth_polyphoniqueAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
