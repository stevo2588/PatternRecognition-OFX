//==============================================================================
//
//  PATTERN RECOGNITION
//
//  Canvas.mm
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#include "MainLevel.h"

#include "testApp.h"

#include "ofMain.h"

MainLevel::MainLevel(testApp& app) : Level(app)
{}

void MainLevel::setup(int mode) {
    app.tpm.registerTouchPatternEvents(*this);
    
    ofBackground( 255 );  // set background color
}

void MainLevel::update() {

}

void MainLevel::draw() {

}

void MainLevel::cleanup() {
    app.tpm.unregisterTouchPatternEvents(*this);
}

void MainLevel::patternDown(TouchPattern & pat) {
    ofPushMatrix();
    ofTranslate(pat.position);
    ofRotate((pat.angle-PI) * (180/PI), 0, 0, 1);
    
    if (pat.registeredPattern == &app.tpm.registeredPatterns[0]) {
        ofSetColor(255,0,0);
        ofEllipse(0, 0, 200, 200);
    }
    else if (pat.registeredPattern == &app.tpm.registeredPatterns[1]) {
        ofSetColor(0,255,0);
        ofEllipse(0, 0, 200, 200);
    }
    else if (pat.registeredPattern == &app.tpm.registeredPatterns[2]) {
        ofSetColor(0,0,255);
        ofEllipse(0, 0, 200, 200);
    }
    
    ofPopMatrix();
}

void MainLevel::patternMoved(TouchPattern & pat) {
    ofPushMatrix();
    ofTranslate(pat.position);
    ofRotate((pat.angle-PI) * (180/PI), 0, 0, 1);
    
    if (pat.registeredPattern == &app.tpm.registeredPatterns[0]) {
        ofSetColor(255,0,0);
        ofEllipse(0, 0, 200, 200);
    }
    else if (pat.registeredPattern == &app.tpm.registeredPatterns[1]) {
        ofSetColor(0,255,0);
        ofEllipse(0, 0, 200, 200);
    }
    else if (pat.registeredPattern == &app.tpm.registeredPatterns[2]) {
        ofSetColor(0,0,255);
        ofEllipse(0, 0, 200, 200);
    }
    
    ofPopMatrix();
}



