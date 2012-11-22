#pragma once

#include "ofMain.h"

class Menu : public ofBaseApp{
    
public:
    Menu();
    void setup(int x, int y, int width, int height, string clipName);
    void update();
    void draw();
    void checkClick(int x, int y);
    
    int posX;
    int posY;
    int width;
    int height;
    bool clicked;
    string clipName;
    
    ofVideoPlayer menuVideo;
    
};