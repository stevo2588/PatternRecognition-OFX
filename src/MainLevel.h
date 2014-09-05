//==============================================================================
//
//  PATTERN RECOGNITION
//
//  Canvas.h
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#ifndef PatternRecognition_Canvas_h
#define PatternRecognition_Canvas_h

#include "Level.h"
#include "TouchPatternListener.h"
#include "Utility.h"

class MainLevel : public Level, public TouchPatternListener {
public:
    MainLevel(testApp& app);
    
    void setup(int mode);
    void update();
    void draw();
    void cleanup();

    // Touch handlers
    void unassignedDown(ofVec2f & touch) {}
    void unassignedMoved(ofVec2f & touch) {}
    void unassignedUp(ofVec2f & touch) {}
    
    void patternDown(TouchPattern & pat);
    void patternMoved(TouchPattern & pat);
    void patternUp(TouchPattern & pat) {}
    
private:

};

#endif
