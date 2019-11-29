/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
    
    void mouseDown (const MouseEvent& e) override
    {
        mouseDrag (e);
    }

    void mouseDrag (const MouseEvent& e) override
    {
        lastMousePosition = e.position;

        frequency = (getHeight() - e.y) * 10.0f;
        amplitude = jmin (0.9f, 0.2f * e.position.x / getWidth());
        std::cout << "amplitude" << amplitude << std::endl;
        std::cout << "frequency" << frequency << std::endl;

        phaseDelta = (float) (MathConstants<double>::twoPi * frequency / sampleRate);

        repaint();
    }

    void mouseUp (const MouseEvent&) override
    {
        amplitude = 0.0f;
        repaint();
    }

private:
    //==============================================================================
    // Your private member variables go here...
    
    float phase       = 1.0f;
    float phaseDelta  = 0.0f;
    
    float frequency   = 5000.0f;
    float amplitude   = 0.8f;
    int expectedSamplesPerBlock = 0;
    double sampleRate = 0.0;
    
    Point<float> lastMousePosition;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
