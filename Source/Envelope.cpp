/*
  ==============================================================================

    Envelope.cpp
    Created: 21 Mar 2018 2:12:11pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(Synth_polyphoniqueAudioProcessor& p):
processor(p)
{
    setSize(400, 200);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 10000.0f);
    attackSlider.setValue(0.1f);
    addAndMakeVisible(&attackSlider);
    
    attackTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    
    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(1.0f, 5000.0f);
    decaySlider.setValue(1.0f);
    addAndMakeVisible(&decaySlider);
    
    decayTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider);
    
    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.0f, 1.0f);
    sustainSlider.setValue(0.8f);
    addAndMakeVisible(&sustainSlider);
    
    sustainTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider);
    
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.0f, 10000.0f);
    releaseSlider.setValue(0.1f);
    addAndMakeVisible(&releaseSlider);
    
    releaseTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);
}

Envelope::~Envelope()
{
    delete releaseTree;
    delete attackTree;
    delete sustainTree;
    delete decayTree;
}

void Envelope::paint (Graphics& g)
{
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);
    
    //static positioning for now due to time, make dynamic later
    g.drawText ("A", 43, 160, 20, 20, Justification::centredTop);
    g.drawText ("D", 67, 160, 20, 20, Justification::centredTop);
    g.drawText ("S", 92, 160, 20, 20, Justification::centredTop);
    g.drawText ("R", 118, 160, 20, 20, Justification::centredTop);
    
    Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
     Rectangle<int> area = getLocalBounds().reduced(40);
    int sliderWidth = 25;
    int sliderHeight = 350;
    
    //draw sliders by reducing area from rectangle above
    attackSlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    decaySlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    sustainSlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    releaseSlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));

}

