/*
  ==============================================================================

    Filter.h
    Created: 21 Mar 2018 9:50:02pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(Synth_polyphoniqueAudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider filtCutoff;
    Slider filtRes;
    ComboBox filterMenu;
    
    AudioProcessorValueTreeState::SliderAttachment *filtVal;
    AudioProcessorValueTreeState::SliderAttachment *resVal;
    
    AudioProcessorValueTreeState::ComboBoxAttachment *filterTypeVal;
    
    Synth_polyphoniqueAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
