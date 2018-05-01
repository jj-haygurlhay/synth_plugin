/*
  ==============================================================================

    Filter.cpp
    Created: 21 Mar 2018 9:50:02pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"

//==============================================================================
Filter::Filter(Synth_polyphoniqueAudioProcessor&p):
processor(p)
{
    setSize(200,200);
    filterMenu.addItem("Low Pass", 1);
    filterMenu.addItem("High Pass", 2);
    filterMenu.addItem("Band Pass", 3);
    filterMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&filterMenu);
    
    
    filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "filterType", filterMenu);
    
    filtCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filtCutoff.setRange(10.0, 10000.0);
    filtCutoff.setValue (5000.0);
    filtCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);

    addAndMakeVisible(&filtCutoff);
    filtVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff", filtCutoff);
    filtCutoff.setSkewFactorFromMidPoint(1000.0);

    filtRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filtRes.setRange(1.0, 5.0);
    filtRes.setValue(1.0);
    filtRes.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);

    addAndMakeVisible(&filtRes);
    resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterResonance", filtRes);

}

Filter::~Filter()
{
    delete filterTypeVal;
    delete filtVal;
    delete resVal;
}

void Filter::paint (Graphics& g)
{
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);
    g.drawText("Cutoff", 40, 100, 40, 10, Justification::centredBottom);
    g.drawText("Resonance", 90, 100, 70, 10, Justification::centredBottom);
    
    Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
    
   
}

void Filter::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    filterMenu.setBounds(area.removeFromTop(20));
    filtCutoff.setBounds (30, 100, 70, 70);
    filtRes.setBounds (100, 100, 70, 70);

}
