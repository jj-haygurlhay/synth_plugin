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
    Mixer();
    ~Mixer();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider volume;
    Slider transpose;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Mixer)
};
