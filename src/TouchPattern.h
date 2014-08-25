//==============================================================================
//
//  PATTERN RECOGNITION
//
//  TouchPattern.h
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#ifndef PatternRecognition_TouchPattern_h
#define PatternRecognition_TouchPattern_h

#include "ofMain.h"

class Pattern;

class TouchPattern {
public:
    TouchPattern();
    
    const Pattern* registeredPattern;
    ofVec2f position;
    float angle;
    std::vector<ofVec2f*> touches;
    
    //int getCount() { return touches.size(); }
    void updateTransform();
};

#endif

