//==============================================================================
//
//  PATTERN RECOGNITION
//
//  MainMenu.h
//
//  Author: Stephen Aldriedge, 2014
//
//==============================================================================

#ifndef PatternRecognition_MainMenu_h
#define PatternRecognition_MainMenu_h

#include "Level.h"

#include "MainLevel.h"
#include "TouchPatternManager.h"
#include "Utility.h"


class MainMenu : public Level, public TouchPatternListener {
public:
    MainMenu(testApp& app, MainLevel &mainLevel, ofTrueTypeFont& f, ofTrueTypeFont& titleFont)
    : Level(app), mainLevel(mainLevel), font(f), titleFont(titleFont),
    startButton(ofRectangle(425, 250, 200, 100), ofColor(255,0,0), ofColor(0,255,0), "Start", font) {}
    
    void setup(int mode);
    void update();
    void draw();
    void cleanup();
    
    void tDown(ofVec2f & touch);
    void tMoved(ofVec2f & touch);
    void tUp(ofVec2f & touch);
    
private:
    MainLevel& mainLevel;
    ofTrueTypeFont &font, &titleFont;
    
    Utility::SimpleButton startButton;
};

#endif

