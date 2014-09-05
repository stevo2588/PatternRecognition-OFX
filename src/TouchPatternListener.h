//==============================================================================
//
//  PATTERN RECOGNITION
//
//  TouchPatternListener.h
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#ifndef PatternRecognition_TouchPatternListener_h
#define PatternRecognition_TouchPatternListener_h

#include "TouchPattern.h"

#include "ofMain.h"

class TouchPatternListener {
public:
    virtual void tDown(ofVec2f & touch) {}
    virtual void tMoved(ofVec2f & touch) {}
    virtual void tUp(ofVec2f & touch) {}
    
    virtual void unassignedDown(ofVec2f & touch) {}
    virtual void unassignedMoved(ofVec2f & touch) {}
    virtual void unassignedUp(ofVec2f & touch) {}
    virtual void unassignedCancelled(ofVec2f & touch) {}
    
    virtual void patternDown(TouchPattern & pat) {}
    virtual void patternMoved(TouchPattern & pat) {}
    virtual void patternUp(TouchPattern & pat) {}
};

#endif // PatternRecognition_TouchPatternListener_h
