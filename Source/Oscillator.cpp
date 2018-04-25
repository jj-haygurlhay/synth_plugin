/*
  ==============================================================================

    Oscillator.cpp
    Created: 18 Mar 2018 10:57:31pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(Synth_polyphoniqueAudioProcessor& p):
processor(p)
{
    setSize(200, 200);
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    oscMenu.addItem("Triangle", 4);
    oscMenu.addItem("Rectangle", 5);
    oscMenu.addItem("Phasor", 6);
    oscMenu.addItem("Cosine", 7);
    oscMenu.addItem("Noise", 8);

    
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "waveform", oscMenu);
    
    osc2Menu.addItem("Sine", 1);
    osc2Menu.addItem("Saw", 2);
    osc2Menu.addItem("Square", 3);
    osc2Menu.addItem("Triangle", 4);
    osc2Menu.addItem("Rectangle", 5);
    osc2Menu.addItem("Phasor", 6);
    osc2Menu.addItem("Cosine", 7);
    osc2Menu.addItem("Noise", 8);

    osc2Menu.setJustificationType(Justification::centred);
    addAndMakeVisible(&osc2Menu);
    osc2Menu.addListener(this);
    
    wave2Selection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "waveform2", osc2Menu);
    
    mixer.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    mixer.setRange(0.0f, 1.0f);
    mixer.setValue(0.5f);
    mixer.setTextBoxStyle(Slider::TextBoxAbove, true, 0, 0);
    addAndMakeVisible(&mixer);
    
    mixerTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mixer", mixer);
}

Oscillator::~Oscillator()
{
    delete waveSelection;
    delete wave2Selection;
    delete mixerTree;
    
}

void Oscillator::paint (Graphics& g)
{
    Rectangle<int> titleArea(0, 10, getWidth(), 20);
    
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Oscillator", titleArea, Justification::centredTop);
    g.drawText("1", 30, 50, 8, 8, Justification::centredLeft);
    g.drawText("2", 30, 75, 8, 8, Justification::centredLeft);

    g.drawText("Mix 1-2", 30, 110, 50, 20, Justification::centredTop);
    
    Rectangle<float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    oscMenu.setBounds(area.removeFromTop(30));
    osc2Menu.setBounds(area.removeFromTop(30));
    mixer.setBounds(area.removeFromLeft(50));
}
void Oscillator::comboBoxChanged(ComboBox *box){

}

