//==============================================================================
//
//  PATTERN RECOGNITION
//
//  testApp.mm
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

//---- CLASS HEADER ----
#include "testApp.h"

//---- STANDARD LIBS ----
#include <vector>
#include <functional>
#include <iterator>


//---------------------------- CONSTRUCTOR ------------------------------------
testApp::testApp()
    : tpm(20,10), mainLevel(*this), mainMenu(*this, mainLevel, verdana14, verdanaLarge), currentLevel(NULL)
{
    // define and register the "known" patterns
    
    // PATTERN 1
    std::vector<ofVec2f> p0(3);
    p0[0] = ofVec2f(14,-64); p0[1] = ofVec2f(-33,32); p0[2] = ofVec2f(20,32);
    knownPatterns[0] = tpm.registerPattern(p0, 7);
    
    // PATTERN 2
    std::vector<ofVec2f> p1(3);
    p1[0] = ofVec2f(-9,24); p1[1] = ofVec2f(55,-16); p1[2] = ofVec2f(-45,-9);
    knownPatterns[1] = tpm.registerPattern(p1, 7);
    
    // PATTERN 3
    std::vector<ofVec2f> p2(3);
    p2[0] = ofVec2f(-15,24); p2[1] = ofVec2f(39,35); p2[2] = ofVec2f(-24,-60);
    knownPatterns[2] = tpm.registerPattern(p2, 7);
}


//---------------------------- STARTLEVEL ------------------------------------
void testApp::startLevel(Level& l, int mode) {
    currentLevel = &l;
    currentLevel->setup(mode);
}


//---------------------------- SETUP ------------------------------------
void testApp::setup(){
    
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);
    ofSetBackgroundAuto(false); //disable automatic background redraw
    
    ofBackground( 0 );
    //old OF default is 96 - but this results in fonts looking larger than in other programs.
	ofTrueTypeFont::setGlobalDpi(72);
    
	verdana14.loadFont("data/verdana.ttf", 22, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);
    
    verdanaLarge.loadFont("data/verdana.ttf", 80, true, true);
	verdanaLarge.setLineHeight(18.0f);
	verdanaLarge.setLetterSpacing(1.037);
    
    ofEnableSmoothing();
    
    startLevel(mainMenu);
}

//---------------------------- UPDATE ------------------------------------
void testApp::update(){
    tpm.updateFrame();
    currentLevel->update();
}

//---------------------------- DRAW ------------------------------------
void testApp::draw(){
    currentLevel->draw();
}


void testApp::exit() {
}

void testApp::lostFocus(){
}

void testApp::gotFocus(){
}

void testApp::gotMemoryWarning(){
}

void testApp::deviceOrientationChanged(int newOrientation){
}




