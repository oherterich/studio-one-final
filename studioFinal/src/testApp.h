#pragma once

#include "ofMain.h"

#include "menu.h"

#define NDETERMINED 30
#define NLOST 27
#define NNOSTALGIC 28
#define NINTROSPECTIVE 26

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
    int moodSelected;
    
    void loadVideos();
    void updateVideos();
    void checkMenu(int x, int y);
    void fadeOutVids(int x, int y);
    void playSong(string song);
    string randomSong();
    
    void playDetermined();
    void playLost();
    void playNostalgic();
    void playIntrospective();
    
    int randomDetermined;
    int randomLost;
    int randomNostalgic;
    int randomIntrospective;
    
    Menu menuNOSTALGIC;
    Menu menuINTROSPECTIVE;
    Menu menuLOST;
    Menu menuDETERMINED;
		
    ofVideoPlayer howareyou;
    ofVideoPlayer fadeOutVid;
    ofVideoPlayer determined[NDETERMINED];
    ofVideoPlayer lost[NLOST];
    ofVideoPlayer nostalgic[NNOSTALGIC];
    ofVideoPlayer introspective[NINTROSPECTIVE];
    
    string chosenSong;
    ofSoundPlayer activeSong;

    
};
