/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SoftSynthAudioProcessor::SoftSynthAudioProcessor()
{
}

SoftSynthAudioProcessor::~SoftSynthAudioProcessor()
{
}

//==============================================================================
const String SoftSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SoftSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SoftSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double SoftSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SoftSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SoftSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SoftSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String SoftSynthAudioProcessor::getProgramName (int index)
{
    return String();
}

void SoftSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SoftSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SoftSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SoftSynthAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void SoftSynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
    
    for (MidiBuffer::Iterator i(midiMessages); i.getNextEvent(m, time);) {
        if (m.isNoteOn()) {
            m = MidiMessage::noteOn(m.getChannel(), m.getNoteNumber(), m.getVelocity());
            synth.keyPressed(m.getNoteNumber(), m.getVelocity());
        } else if (m.isNoteOff()) {
            m = MidiMessage::noteOff(m.getChannel(), m.getNoteNumber(), m.getVelocity());
            synth.keyReleased(m.getNoteNumber());
        }
        
        processedMidi.addEvent(m, time);
    }
    
    auto synthBuffer = synth.getNextBuffer(buffer.getNumSamples());
    float *leftData = buffer.getWritePointer(0);
    float *rightData = buffer.getWritePointer(1);
    for (int i = 0; i < buffer.getNumSamples(); ++i) {
        leftData[i] = synthBuffer[i];
        rightData[i] = synthBuffer[i];
    }
    
    midiMessages.swapWith(processedMidi);
}

//==============================================================================
bool SoftSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SoftSynthAudioProcessor::createEditor()
{
    return new SoftSynthAudioProcessorEditor (*this);
}

//==============================================================================
void SoftSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SoftSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoftSynthAudioProcessor();
}
