//==============================================================================
//
//  PATTERN RECOGNITION
//
//  MainMenu.mm
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#include "MainMenu.h"

#include "testApp.h"

#include "ofMain.h"

void MainMenu::setup(int mode) {
    app.tpm.registerTouchPatternEvents(*this);
}

void MainMenu::update() {
    // check if start button was pressed
    
    // change to selection screen
    //startLevel(selectionScreen);
}

void MainMenu::draw() {
    ofBackground( 0 );  // set background color
    
    ofSetColor(255);
    titleFont.drawString("PATTERN RECOGNITION", 315, 170);
    
    startButton.draw();
}

void MainMenu::cleanup() {
    app.tpm.unregisterTouchPatternEvents(*this);
}

void MainMenu::tDown(ofVec2f & touch) {
    startButton.touchDown(touch);
}
void MainMenu::tMoved(ofVec2f & touch) {}
void MainMenu::tUp(ofVec2f & touch) {
    if(startButton.touchUp(touch)) {
        startLevel(mainLevel, 0);
    }
}