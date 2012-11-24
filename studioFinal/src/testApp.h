#pragma once

#include "ofMain.h"

#include "menu.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    bool firstTimeFaded;
    string songMood;
    
    void checkMenu(int x, int y);
    void fadeOutVids(int x, int y);
    void playSong(string song);
    string randomSong();
    
    Menu menuNOSTALGIC;
    Menu menuINTROSPECTIVE;
    Menu menuLOST;
    Menu menuDETERMINED;
		
    ofVideoPlayer howareyou;
    ofVideoPlayer fadeOutVid;
    
//    ofSoundPlayer nostalgic01;
//    ofSoundPlayer nostalgic02;
//    ofSoundPlayer nostalgic03;
//    ofSoundPlayer nostalgic04;
//    ofSoundPlayer introspective01;
//    ofSoundPlayer introspective02;
//    ofSoundPlayer introspective03;
//    ofSoundPlayer introspective04;
//    ofSoundPlayer lost01;
//    ofSoundPlayer lost02;
//    ofSoundPlayer lost03;
//    ofSoundPlayer lost04;
//    ofSoundPlayer determined01;
//    ofSoundPlayer determined02;
//    ofSoundPlayer determined03;
//    ofSoundPlayer determined04;
    
    string chosenSong;
    ofSoundPlayer activeSong;



    
};
