/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Strip.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Strip::Strip ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centred);
    comboBox->setTextWhenNothingSelected (String::empty);
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Piano,"), 1);
    comboBox->addItem (TRANS("Violin,"), 2);
    comboBox->addItem (TRANS("Flute"), 3);
    comboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Strip::~Strip()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Strip::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setGradientFill (ColourGradient (Colours::red,
                                       50.0f, 50.0f,
                                       Colours::green,
                                       100.0f, 100.0f,
                                       false));
    g.fillPath (internalPath1);

    g.setColour (Colour (0xff196a81));
    g.fillRect (0, 0, 800, 1);

    g.setColour (Colour (0xff196a81));
    g.fillRect (0, 150, 800, 1);

    g.setColour (Colour (0xff196a81));
    g.fillRect (200, 0, 1, 150);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Strip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    comboBox->setBounds (100 - (150 / 2), 70 - (24 / 2), 150, 24);
    internalPath1.clear();
    internalPath1.setUsingNonZeroWinding (false);
    internalPath1.startNewSubPath (366.0f, 320.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Strip::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Strip" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffff">
    <PATH pos="0 0 100 100" fill="linear: 50 50, 100 100, 0=ffff0000, 1=ff008000"
          hasStroke="0" nonZeroWinding="0">s 366 320 x</PATH>
    <RECT pos="0 0 800 1" fill="solid: ff196a81" hasStroke="0"/>
    <RECT pos="0 150 800 1" fill="solid: ff196a81" hasStroke="0"/>
    <RECT pos="200 0 1 150" fill="solid: ff196a81" hasStroke="0"/>
  </BACKGROUND>
  <COMBOBOX name="new combo box" id="35af25f0109ffbe0" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="100c 70c 150 24" editable="0"
            layout="36" items="Piano,&#10;Violin,&#10;Flute" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
