/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include <vector>


//==============================================================================
/**
*/
class SoftSynthAudioProcessorEditor  : public AudioProcessorEditor, private SliderListener, private Button::Listener, private ComboBox::Listener
{
public:
    SoftSynthAudioProcessorEditor (SoftSynthAudioProcessor&);
    ~SoftSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    void sliderValueChanged(Slider *slider) override;
    void buttonClicked(Button *button) override;
    void buttonStateChanged(Button *button) override;
    void comboBoxChanged(ComboBox *box) override;
    void initSlider(Slider *slider, double min, double max, const std::string &suffix, double val, const std::string &labelText);
    void initWaveformSelector(ComboBox *box, const std::string &labelText);
    
    SoftSynthAudioProcessor& processor;
    
    /* Synth Sliders */
    Slider filterCutoffSlider;
    Slider filterResonanceSlider;
    
    Slider volumeLFOFrequencySlider;
    Slider volumeLFOAmplitudeSlider;
    Slider filterLFOFrequencySlider;
    Slider filterLFOAmplitudeSlider;
    
    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;
    
    Slider oscillator1TableFadeSlider;
    Slider oscillator2TableFadeSlider;
    
    std::vector<Component*> sliders;
    
    ComboBox oscillator1Waveform1;
    ComboBox oscillator1Waveform2;
    ComboBox oscillator2Waveform1;
    ComboBox oscillator2Waveform2;
    
    ToggleButton oscillator2Toggle;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftSynthAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
