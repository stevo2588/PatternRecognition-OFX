//==============================================================================
//
//  PATTERN RECOGNITION
//
//  Pattern.h
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#ifndef Colors_TouchShape_h
#define Colors_TouchShape_h

#include "ofMain.h"

#include <vector>

class Pattern {
public:
    Pattern(std::vector<ofVec2f> points, int tol);
    
    std::vector<ofVec2f> vectors;
    std::vector<float> angles; // holds angles between vectors and the first vector
	int tolerance;
    
	std::vector<ofVec2f*> tryPoints(const std::vector<ofVec2f*>& points, unsigned &usedTolerance);
private:
    bool tryPoints(const ofVec2f* mainPt, const std::vector<ofVec2f *> &t, unsigned int &usedTolerance);
};

#endif

