/*
  ==============================================================================

    Mixer.h
    Created: 30 Apr 2018 9:04:35am
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/*
*/
class Mixer    : public Component
{
public:
    Mixer(Synth_polyphoniqueAudioProcessor&);
    ~Mixer();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider volume;
    Slider transpose;
    
    AudioProcessorValueTreeState::SliderAttachment *volVal;
    AudioProcessorValueTreeState::SliderAttachment *pitchVal;
    
    Synth_polyphoniqueAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Mixer)
};
