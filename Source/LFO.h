/*
  ==============================================================================

    LFO.h
    Created: 8 Apr 2018 5:21:33pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/*
*/
class LFO    : public Component,
               private ComboBox::Listener

{
public:
    LFO(Synth_polyphoniqueAudioProcessor&);
    ~LFO();

    void paint (Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(ComboBox*) override;
    

private:
    //ComboBox onSwitch;
    ComboBox oscChoice;
    ComboBox parametre;
    Slider rate;
    Slider amount;
    
    //AudioProcessorValueTreeState::ComboBoxAttachment *onSwitchVal;
    AudioProcessorValueTreeState::ComboBoxAttachment *LFOTypeVal;
    AudioProcessorValueTreeState::ComboBoxAttachment *parametreTypeVal;
    AudioProcessorValueTreeState::SliderAttachment *rateVal;
    AudioProcessorValueTreeState::SliderAttachment *amountVal;

    Synth_polyphoniqueAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFO)
};
