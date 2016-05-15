/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SoftSynthAudioProcessorEditor::SoftSynthAudioProcessorEditor (SoftSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    filterCutoffSlider.setSliderStyle(Slider::LinearVertical);
    filterCutoffSlider.setRange(0.0, 1.0);
    filterCutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    filterCutoffSlider.setPopupDisplayEnabled(true, this);
    filterCutoffSlider.setTextValueSuffix(" Filter Cutoff");
    filterCutoffSlider.setValue(1.0);
    addAndMakeVisible(&filterCutoffSlider);
    filterCutoffSlider.addListener(this);
    
    filterResonanceSlider.setSliderStyle(Slider::LinearVertical);
    filterResonanceSlider.setRange(0.0, 1.0);
    filterResonanceSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    filterResonanceSlider.setPopupDisplayEnabled(true, this);
    filterResonanceSlider.setTextValueSuffix(" Filter Resonance");
    filterResonanceSlider.setValue(0.0);
    addAndMakeVisible(&filterResonanceSlider);
    filterResonanceSlider.addListener(this);
    
    volumeLFOFrequencySlider.setSliderStyle(Slider::LinearVertical);
    volumeLFOFrequencySlider.setRange(0.0, 20.0);
    volumeLFOFrequencySlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    volumeLFOFrequencySlider.setPopupDisplayEnabled(true, this);
    volumeLFOFrequencySlider.setTextValueSuffix(" Volume LFO F");
    volumeLFOFrequencySlider.setValue(0.0);
    addAndMakeVisible(&volumeLFOFrequencySlider);
    volumeLFOFrequencySlider.addListener(this);
    
    volumeLFOAmplitudeSlider.setSliderStyle(Slider::LinearVertical);
    volumeLFOAmplitudeSlider.setRange(0.0, 1.0);
    volumeLFOAmplitudeSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    volumeLFOAmplitudeSlider.setPopupDisplayEnabled(true, this);
    volumeLFOAmplitudeSlider.setTextValueSuffix(" Volume LFO A");
    volumeLFOAmplitudeSlider.setValue(0.0);
    addAndMakeVisible(&volumeLFOAmplitudeSlider);
    volumeLFOAmplitudeSlider.addListener(this);
    
    initSlider(&filterLFOFrequencySlider, 0.0, 20.0, " Filter LFO F", 0.0);
    initSlider(&filterLFOAmplitudeSlider, 0.0, 1.0, " Filter LFO A", 0.0);
}

SoftSynthAudioProcessorEditor::~SoftSynthAudioProcessorEditor()
{
}

//==============================================================================
void SoftSynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Soft Synth", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void SoftSynthAudioProcessorEditor::resized()
{
    filterCutoffSlider.setBounds(10, 10, 20, getHeight() - 60);
    filterResonanceSlider.setBounds(30, 10, 20, getHeight() - 60);
    volumeLFOFrequencySlider.setBounds(50, 10, 20, getHeight() - 60);
    volumeLFOAmplitudeSlider.setBounds(70, 10, 20, getHeight() - 60);
    filterLFOFrequencySlider.setBounds(90, 10, 20, getHeight() - 60);
    filterLFOAmplitudeSlider.setBounds(110, 10, 20, getHeight() - 60);
}

void SoftSynthAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &filterCutoffSlider) {
        processor.synth.setMainFilterPitchCutoff(filterCutoffSlider.getValue());
    } else if (slider == &filterResonanceSlider) {
        processor.synth.setMainFilterResonance(filterResonanceSlider.getValue());
    } else if (slider == &volumeLFOFrequencySlider) {
        processor.synth.setVolumeLFOFrequency(volumeLFOFrequencySlider.getValue());
    } else if (slider == &volumeLFOAmplitudeSlider) {
        processor.synth.setVolumeLFOAmplitude(volumeLFOAmplitudeSlider.getValue());
    } else if (slider == &filterLFOFrequencySlider) {
        processor.synth.setFilterLFOFrequency(filterLFOFrequencySlider.getValue());
    } else if (slider == &filterLFOAmplitudeSlider) {
        processor.synth.setFilterLFOAmplitude(filterLFOAmplitudeSlider.getValue());
    }
}

void SoftSynthAudioProcessorEditor::initSlider(Slider *slider, double min, double max, const std::string &suffix, double val)
{
    slider->setSliderStyle(Slider::LinearVertical);
    slider->setRange(min, max);
    slider->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    slider->setPopupDisplayEnabled(true, this);
    slider->setTextValueSuffix(suffix);
    slider->setValue(val);
    addAndMakeVisible(slider);
    slider->addListener(this);
}

