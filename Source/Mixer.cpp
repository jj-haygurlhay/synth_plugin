/*
  ==============================================================================

    Mixer.cpp
    Created: 30 Apr 2018 9:04:35am
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Mixer.h"

//==============================================================================
Mixer::Mixer(Synth_polyphoniqueAudioProcessor&p):
processor(p)
{
    setSize(200, 200);
    volume.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    volume.setRange(-48.0, 6.0);
    volume.setValue (0.0);
    volume.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&volume);
    
    volVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "volume", volume);
    
    transpose.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    transpose.setRange(-48, 48);
    transpose.setValue (0.0);
    transpose.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&transpose);
    pitchVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "transpose", transpose);
    
}

Mixer::~Mixer()
{
    delete volVal;
    delete pitchVal;
}

void Mixer::paint (Graphics& g)
{
   
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    

    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Mixer", titleArea, Justification::centredTop);
        
    g.drawText("Volume", 30, 75, 8, 8, Justification::centredLeft);
    g.drawText("Transpose", 100, 75, 8, 8, Justification::centredLeft);
    
    Rectangle <float> area (25, 25, 350, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
    
}

void Mixer::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    //onSwitch.setBounds(area.removeFromTop(20));
    
    volume.setBounds (35, 100, 70, 70);
    transpose.setBounds(105, 100, 70, 70);
    
}
