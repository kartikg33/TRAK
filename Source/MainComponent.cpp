/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "Strip.cpp"
#include "Grid.cpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent,
                                private TextButton::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    {
        setSize (800, 600);

        // specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
        
        addAndMakeVisible (listenButton = new TextButton("TRAK"));
        listenButton->addListener (this);
        listenButton->setBounds(400-50, 275-50, 100, 100);
        
        /*
        listenButton->setImages (false, true, true,
                                Image(), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));
         */
        
        addAndMakeVisible(description = new Label());
        description->setBounds(400-250, 375-25, 500, 50);
        description->setText("click to track singing or humming", dontSendNotification);
        description->setColour(juce::Label::textColourId, Colours::white);
        description->setJustificationType (Justification::centred);
        description->setEditable (false, false, false);
        description->setFont(Font ("Century Gothic", 30.00f, Font::plain));
    }

    ~MainContentComponent()
    {
        shutdownAudio();
        listenButton = nullptr;
        stripOne = nullptr;
        description = nullptr;
    }

    //=======================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        bufferToFill.clearActiveBufferRegion();
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //=======================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::black);


        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.

    }
    
    //=======================================================================
    
    void buttonClicked (Button* buttonThatWasClicked)
    {
        //[UserbuttonClicked_Pre]
        //[/UserbuttonClicked_Pre]
        
        if (buttonThatWasClicked == listenButton)
        {
            //[UserButtonCode_listenButton] -- add your button handler code here..
            listened = !listened;
            listening();
            if(listened){
                addAndMakeVisible(stripOne = new Strip());
                stripOne->setBounds(0, 0, 800, 200);
            }
            //[/UserButtonCode_listenButton]
        }
        
        //[UserbuttonClicked_Post]
        //[/UserbuttonClicked_Post]
    }
    
    void listening(void){
        if(listened){
            description->setText("click to track singing or humming", dontSendNotification);
        } else {
            description->setText("listening...", dontSendNotification);
        }
        
    
        
    }

private:
    //==============================================================================

    // Your private member variables go here...
    ScopedPointer<Label> description;
    ScopedPointer<TextButton> listenButton;
    ScopedPointer<Strip> stripOne;
    bool listened = true;
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
