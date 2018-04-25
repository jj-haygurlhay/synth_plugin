/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Synth_polyphoniqueAudioProcessorEditor::Synth_polyphoniqueAudioProcessorEditor (Synth_polyphoniqueAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui(p), envGui(p), filtGui(p), lfoGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 500);
    
    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&filtGui);
    addAndMakeVisible(&lfoGui);
    
}

Synth_polyphoniqueAudioProcessorEditor::~Synth_polyphoniqueAudioProcessorEditor()
{
    
}

//==============================================================================
void Synth_polyphoniqueAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

   
    g.drawFittedText ("Yo Momma's synth!", getLocalBounds(), Justification::centred, 1);
}

void Synth_polyphoniqueAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    const int componentWidth = 200;
    const int componentHeight = 200;
    
    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    filtGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    lfoGui.setBounds(50, 250, 400, 200);
    
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
