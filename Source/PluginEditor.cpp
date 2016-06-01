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
    setSize (370, 350);
    
    initSlider(&filterCutoffSlider, 0.0, 1.0, " %", 1.0, "Cutoff");
    initSlider(&filterResonanceSlider, 0.0, 1.0, " %", 0.0, "Resonance");
    initFilterTypeSelector(&filterType, "Filter Type");
    
    initSlider(&volumeLFOFrequencySlider, 0.0, 20.0, " Hz", 0.0, "VLFO Frequency");
    initSlider(&volumeLFOAmplitudeSlider, 0.0, 1.0, " %", 0.0, "VLFO Amplitude");
    
    initSlider(&filterLFOFrequencySlider, 0.0, 20.0, " Hz", 0.0, "FLFO Frequency");
    initSlider(&filterLFOAmplitudeSlider, 0.0, 1.0, " %", 0.0, "FLFO Amplitude");
    
    initSlider(&attackSlider, 0.0, 2.0, " seconds", 0.01, "Attack");
    initSlider(&decaySlider, 0.0, 2.0, " seconds", 0.01, "Decay");
    initSlider(&sustainSlider, 0.0, 1.0, " %", 1.0, "Sustain Level");
    initSlider(&releaseSlider, 0.0, 2.0, " seconds", 0.01, "Release");
    
    initWaveformSelector(&oscillator1Waveform1, "Osc 1 Waveform 1");
    initWaveformSelector(&oscillator1Waveform2, "Osc 1 Waveform 2");
    initVoiceCountSelector(&oscillator1VoiceCount, "Osc 1 Voices");
    initSlider(&oscillator1TableFadeSlider, 0.0, 1.0, " %", 0.0, "Osc 1 Table");
    
    oscillator2Toggle.setButtonText("Osc 2");
    oscillator2Toggle.addListener(this);
    addAndMakeVisible(&oscillator2Toggle);
    sliders.push_back(&oscillator2Toggle);
    
    initWaveformSelector(&oscillator2Waveform1, "Osc 2 Waveform 1");
    initWaveformSelector(&oscillator2Waveform2, "Osc 2 Waveform 2");
    initVoiceCountSelector(&oscillator2VoiceCount, "Osc 2 Voices");
    initSlider(&oscillator2TableFadeSlider, 0.0, 1.0, " %", 0.0, "Osc 2 Table");
    
    resized();
}

SoftSynthAudioProcessorEditor::~SoftSynthAudioProcessorEditor()
{
}

//==============================================================================
void SoftSynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

//    g.setColour (Colours::black);
//    g.setFont (15.0f);
//    g.drawFittedText ("Soft Synth", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void SoftSynthAudioProcessorEditor::resized()
{
    int lastSliderEnd = 10;
    int height = 30;
    for (auto slider : sliders) {
        slider->setBounds(lastSliderEnd, height, 60, 60);
        lastSliderEnd += slider->getWidth() + 10;
        
        if (slider->getWidth() + lastSliderEnd > getWidth()) {
            height += slider->getHeight() + 20;
            lastSliderEnd = 10;
        }
    }
    
//    filterCutoffSlider.setBounds(10, 10, 20, getHeight() - 60);
//    filterResonanceSlider.setBounds(30, 10, 20, getHeight() - 60);
//    volumeLFOFrequencySlider.setBounds(50, 10, 20, getHeight() - 60);
//    volumeLFOAmplitudeSlider.setBounds(70, 10, 20, getHeight() - 60);
//    filterLFOFrequencySlider.setBounds(90, 10, 20, getHeight() - 60);
//    filterLFOAmplitudeSlider.setBounds(110, 10, 20, getHeight() - 60);
//    attackSlider.setBounds(130, 10, 20, getHeight() - 60);
//    decaySlider.setBounds(150, 10, 20, getHeight() - 60);
//    sustainSlider.setBounds(170, 10, 20, getHeight() - 60);
//    releaseSlider.setBounds(190, 10, 20, getHeight() - 60);
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
    } else if (slider == &attackSlider) {
        processor.synth.setNoteAttackDuration(attackSlider.getValue());
    } else if (slider == &decaySlider) {
        processor.synth.setNoteDecayDuration(decaySlider.getValue());
    } else if (slider == &sustainSlider) {
        processor.synth.setNoteSustainLevel(sustainSlider.getValue());
    } else if (slider == &releaseSlider) {
        processor.synth.setNoteReleaseDuration(releaseSlider.getValue());
    } else if (slider == &oscillator1TableFadeSlider) {
        processor.synth.setTableFadePercentage(0, oscillator1TableFadeSlider.getValue());
    } else if (slider == &oscillator2TableFadeSlider) {
        processor.synth.setTableFadePercentage(1, oscillator2TableFadeSlider.getValue());
    }
}

void SoftSynthAudioProcessorEditor::buttonStateChanged(Button *button)
{
}

void SoftSynthAudioProcessorEditor::buttonClicked(Button *button)
{
    if (button == &oscillator2Toggle) {
        processor.synth.toggleOscillator2();
    }
}

void SoftSynthAudioProcessorEditor::comboBoxChanged(ComboBox *box)
{
    if (box == &oscillator1Waveform1) {
        processor.synth.setOscillatorWavetable(0, 0, box->getSelectedId());
    } else if (box == &oscillator1Waveform2) {
        processor.synth.setOscillatorWavetable(0, 1, box->getSelectedId());
    } else if (box == &oscillator2Waveform1) {
        processor.synth.setOscillatorWavetable(1, 0, box->getSelectedId());
    } else if (box == &oscillator2Waveform2) {
        processor.synth.setOscillatorWavetable(1, 1, box->getSelectedId());
    } else if (box == &oscillator1VoiceCount) {
        processor.synth.setOscillatorVoiceCount(0, box->getSelectedId());
    } else if (box == &oscillator2VoiceCount) {
        processor.synth.setOscillatorVoiceCount(1, box->getSelectedId());
    } else if (box == &filterType) {
        processor.synth.setFilterType(static_cast<FilterType>(box->getSelectedId()));
    }
}

void SoftSynthAudioProcessorEditor::initSlider(Slider *slider, double min, double max, const std::string &suffix, double val, const std::string &labelText)
{
    slider->setSliderStyle(Slider::Rotary);
    slider->setRange(min, max);
    slider->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    slider->setPopupDisplayEnabled(true, this);
    slider->setTextValueSuffix(suffix);
    slider->setValue(val);
    addAndMakeVisible(slider);
    slider->addListener(this);
    
    Label *label = new Label;
    addAndMakeVisible(label);
    Font font;
    font.setTypefaceName("Avenir Next");
    font.setHorizontalScale(0.75);
    label->setFont(font);
    label->setText(labelText, dontSendNotification);
    label->attachToComponent(slider, false);
    
    sliders.push_back(slider);
}

void SoftSynthAudioProcessorEditor::initWaveformSelector(ComboBox *box, const std::string &labelText)
{
    box->addItem("Sawtooth", 1);
    box->addItem("Square", 2);
    box->addItem("Sine", 3);
    box->addListener(this);
    box->setSelectedId(1);
    addAndMakeVisible(box);
    Label *label = new Label;
    addAndMakeVisible(label);
    Font font;
    font.setTypefaceName("Avenir Next");
    font.setHorizontalScale(0.75);
    label->setFont(font);
    label->setText(labelText, dontSendNotification);
    label->attachToComponent(box, false);
    sliders.push_back(box);
}

void SoftSynthAudioProcessorEditor::initVoiceCountSelector(juce::ComboBox *box, const std::string &labelText)
{
    box->addItem("1", 1);
    box->addItem("2", 2);
    box->addItem("3", 3);
    box->addItem("4", 4);
    box->setSelectedId(1);
    box->addListener(this);
    addAndMakeVisible(box);
    
    Label *label = new Label;
    addAndMakeVisible(label);
    Font font;
    font.setTypefaceName("Avenir Next");
    font.setHorizontalScale(0.75);
    label->setFont(font);
    label->setText(labelText, dontSendNotification);
    label->attachToComponent(box, false);
    sliders.push_back(box);
}

void SoftSynthAudioProcessorEditor::initFilterTypeSelector(juce::ComboBox *box, const std::string &labelText)
{
    box->addItem("Low Pass", 1);
    box->addItem("High Pass", 2);
    box->addItem("Band Pass", 3);
    box->setSelectedId(1);
    box->addListener(this);
    addAndMakeVisible(box);
    
    Label *label = new Label;
    addAndMakeVisible(label);
    Font font;
    font.setTypefaceName("Avenir Next");
    font.setHorizontalScale(0.75);
    label->setFont(font);
    label->setText(labelText, dontSendNotification);
    label->attachToComponent(box, false);
    sliders.push_back(box);
}
