//==============================================================================
//
//  PATTERN RECOGNITION
//
//  TouchPatternManager.h
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#ifndef PatternRecognition_TouchManager_h
#define PatternRecognition_TouchManager_h

#include "Pattern.h"
#include "TouchPattern.h"
#include "TouchPatternListener.h"

#include "ofMain.h"
#include "ofxMultiTouchListener.h"

class Level;

class TouchPatternManager : public ofxMultiTouchListener {
public:
    TouchPatternManager(size_t maxTouches, size_t maxPatDetection)
    : maxTouches(maxTouches), maxPatDetection(maxPatDetection), detectedPatterns(maxPatDetection),
      patInUse(maxPatDetection, false), frameDelay(15)
    {
        unassigned.reserve(maxTouches);
        registeredPatterns.reserve(maxPatDetection);
        
        ofRegisterTouchEvents(this);
    }
    
    void registerTouchPatternEvents(TouchPatternListener& tpl) { listeners.push_back( &tpl ); }
    void unregisterTouchPatternEvents(TouchPatternListener& tpl) {
        listeners.erase(std::remove(listeners.begin(), listeners.end(), &tpl), listeners.end());
    }
    
    const Pattern* registerPattern(std::vector<ofVec2f> points, int tolerance);
    void unregisterAllPatterns();
    
    const std::vector<ofVec2f*>& getUnassigned() const { return unassigned; }
    
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch) {}
    void touchCancelled(ofTouchEventArgs & touch) {}
    
    void tDown(ofVec2f & touch);
    void tMoved(ofVec2f & touch);
    void tUp(ofVec2f & touch);
    
    void unassignedDown(ofVec2f & touch);
    void unassignedMoved(ofVec2f & touch);
    void unassignedUp(ofVec2f & touch);
    void unassignedCancelled(ofVec2f & touch);
    
    void patternDown(TouchPattern & pat, size_t index);
    void patternMoved(TouchPattern & pat);
    void patternUp(TouchPattern & pat, size_t index, size_t touchUpIndex);
    
    void updateFrame();
    
    std::vector<Pattern> registeredPatterns; // TODO: private
    
private:
    size_t maxTouches;
    size_t maxPatDetection;
    
    std::map<int,ofVec2f> touches;
    std::vector<ofVec2f*> unassigned;
    //std::vector<Pattern> registeredPatterns;
    
    std::vector<TouchPattern> detectedPatterns;
    std::vector<bool> patInUse;
    
    std::vector<TouchPatternListener*> listeners;
    
    // this is how many frames we wait before we actually check for a pattern
    unsigned frameDelay;
    
    std::vector<unsigned> patternCheckDelay;
    
    void lookForPattern();
    void registerDetectedPattern(TouchPattern tp);
    int getUnusedPatIndex();
};



#endif
