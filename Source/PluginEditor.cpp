/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TutorialProjectAudioProcessorEditor::TutorialProjectAudioProcessorEditor (TutorialProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    // This is where our plugin’s editor size is set.
    setSize (200, 200);

    // these define the parameters of our slider object
    midiVolume.setSliderStyle (juce::Slider::LinearBarVertical);
    midiVolume.setRange (0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled (true, false, this);
    midiVolume.setTextValueSuffix (" Volume");
    midiVolume.setValue (1.0);

    // adds the slider to the editor
    addAndMakeVisible (&midiVolume);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    midiVolume.addListener(this);
}

void TutorialProjectAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.noteOnVel = midiVolume.getValue();
}

TutorialProjectAudioProcessorEditor::~TutorialProjectAudioProcessorEditor()
{
}

//==============================================================================
void TutorialProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    g.fillAll (juce::Colours::white);
    g.setColour (juce::Colours::black);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void TutorialProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
}
