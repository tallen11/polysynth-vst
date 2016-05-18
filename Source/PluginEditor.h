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


//==============================================================================
/**
*/
class SoftSynthAudioProcessorEditor  : public AudioProcessorEditor, private SliderListener
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
    void initSlider(Slider *slider, double min, double max, const std::string &suffix, double val);
    
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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftSynthAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
