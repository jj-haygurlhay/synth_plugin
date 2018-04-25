/*
  ==============================================================================

    Oscillator.h
    Created: 18 Mar 2018 10:57:31pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator    : public Component,
                      private ComboBox::Listener
{
public:
    Oscillator(Synth_polyphoniqueAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;
    
private:
    ComboBox oscMenu;
    ComboBox osc2Menu;
    Slider mixer;
    
    AudioProcessorValueTreeState::SliderAttachment* mixerTree;
    
    AudioProcessorValueTreeState::ComboBoxAttachment* waveSelection;
    AudioProcessorValueTreeState::ComboBoxAttachment* wave2Selection;
    
    Synth_polyphoniqueAudioProcessor & processor;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
