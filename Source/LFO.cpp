/*
  ==============================================================================

    LFO.cpp
    Created: 8 Apr 2018 5:21:33pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFO.h"

//==============================================================================
LFO::LFO(Synth_polyphoniqueAudioProcessor&p):
processor(p)
{
    setSize(400,200);
    /*onSwitch.addItem("Off", 1);
    onSwitch.addItem("On",2);
    onSwitch.setJustificationType(Justification::centred);
    addAndMakeVisible(&onSwitch);
    onSwitch.addListener(this);
    
    onSwitchVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "on switch", onSwitch);*/
    
    oscChoice.addItem("Sine", 1);
    oscChoice.addItem("Saw", 2);
    oscChoice.addItem("Square", 3);
    oscChoice.addItem("Triangle", 4);
    oscChoice.addItem("Rectangle", 5);
    oscChoice.addItem("Phasor", 6);
    oscChoice.addItem("Cosine", 7);
    
    oscChoice.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscChoice);
    oscChoice.addListener(this);
    
    LFOTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "oscillator", oscChoice);
    
    parametre.addItem("Filter Frequency", 1);
    parametre.addItem("Filter Resonance", 2);
    parametre.setJustificationType(Justification::centred);
    addAndMakeVisible(&parametre);
    parametre.addListener(this);
    
    parametreTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "assigned parameter", parametre);
    
    rate.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rate.setRange(0.0, 250.0);
    rate.setValue (0.0);
    rate.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&rate);
    
    rateVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "rate", rate);
    
    amount.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    amount.setRange(0.0, 1.0);
    amount.setValue (0.0);
    amount.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&amount);
    
    amountVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "amount", amount);

    
}

LFO::~LFO()
{
    //delete onSwitchVal;
    delete LFOTypeVal;
    delete parametreTypeVal;
    delete rateVal;
    delete amountVal;
}

void LFO::paint (Graphics& g)
{

    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("LFO", titleArea, Justification::centredTop);
    
    //g.drawText("On/Off", 30, 50, 8, 8, Justification::centredLeft);
    g.drawText("Osc", 30, 75, 8, 8, Justification::centredLeft);
    g.drawText("Parametre", 100, 75, 8, 8, Justification::centredBottom);
    g.drawText("Rate", 100, 100, 70, 70, Justification::centredBottom);
    g.drawText("Amount", 225, 100, 70, 70, Justification::centredBottom);

    
    Rectangle <float> area (25, 25, 350, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void LFO::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    //onSwitch.setBounds(area.removeFromTop(20));
    oscChoice.setBounds(area.removeFromTop(20));
    parametre.setBounds (area.removeFromTop(20));
    rate.setBounds (100, 100, 70, 70);
    amount.setBounds(225, 100, 70, 70);
    
}
void LFO::comboBoxChanged(ComboBox *box){
    
}
