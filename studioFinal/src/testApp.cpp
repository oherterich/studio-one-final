#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    ofSetColor(255,255,255);
    
    firstTimeFaded = true; 
    moodSelected = 0;
    
    howareyou.loadMovie("movies/howareyou.mp4");
    howareyou.play();
    
    loadVideos();
    
    menuNOSTALGIC.setup(30,385,135,25,"menunostalgic");
    menuINTROSPECTIVE.setup(45,430,110,25, "menuintrospective");
    menuLOST.setup(25,475, 100, 25,"menulost");
    menuDETERMINED.setup(15,520,115,20, "menudetermined");
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    howareyou.update();
    
    menuNOSTALGIC.update();
    menuINTROSPECTIVE.update();
    menuLOST.update();
    menuDETERMINED.update();
    
    fadeOutVid.update();
    updateVideos();
    
    playSong(songMood);
    
    ofSoundUpdate();
    
    if (fadeOutVid.getIsMovieDone()) {
        fadeOutVid.closeMovie();
        
        switch (moodSelected) {
                
            case 1 :
                nostalgic[randomNostalgic].play();
                nostalgic[randomNostalgic].setLoopState(OF_LOOP_NONE);
                break;
                
            case 2 :
                introspective[randomIntrospective].play();
                introspective[randomIntrospective].setLoopState(OF_LOOP_NONE);
                break;
                
            case 3 :
                lost[randomLost].play();
                lost[randomLost].setLoopState(OF_LOOP_NONE);
                break;
                
            case 4 :
                determined[randomDetermined].play();
                determined[randomDetermined].setLoopState(OF_LOOP_NONE);
                break;
        }

        

    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    howareyou.draw(0,0);
    
    menuNOSTALGIC.draw();
    menuINTROSPECTIVE.draw();
    menuLOST.draw();
    menuDETERMINED.draw();
    
    fadeOutVid.draw(0,0);
    
    if (activeSong.getIsPlaying()) {
        switch (moodSelected) {
                
            case 1 :
                playNostalgic();
                break;
                
            case 2 :
                playIntrospective();
                break;
                
            case 3 :
                playLost();
                break;
                
            case 4 :
                playDetermined();
                break;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    checkMenu(x,y);
    fadeOutVids(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::checkMenu(int x, int y){
    
    menuNOSTALGIC.checkClick(x,y);
    if (menuNOSTALGIC.clicked == true) {
        menuINTROSPECTIVE.clicked = false;
        menuLOST.clicked = false;
        menuDETERMINED.clicked = false;
        
    }
    
    menuINTROSPECTIVE.checkClick(x,y);
    if (menuINTROSPECTIVE.clicked == true) {
        menuNOSTALGIC.clicked = false;
        menuLOST.clicked = false;
        menuDETERMINED.clicked = false;
        
    }
    
    menuLOST.checkClick(x,y);
    if (menuLOST.clicked == true) {
        menuINTROSPECTIVE.clicked = false;
        menuNOSTALGIC.clicked = false;
        menuDETERMINED.clicked = false;
        
    }
    
    menuDETERMINED.checkClick(x,y);
    if (menuDETERMINED.clicked == true) {
        menuINTROSPECTIVE.clicked = false;
        menuLOST.clicked = false;
        menuNOSTALGIC.clicked = false;
        
    }
    
    
    
    if (menuNOSTALGIC.clicked == true || menuINTROSPECTIVE.clicked == true || menuLOST.clicked == true || menuDETERMINED.clicked == true) {
        howareyou.closeMovie();
    }
}

void testApp::fadeOutVids(int x, int y) {
    
    if (x > 400 && x < 545 && y > 270 && y < 295) {
        if (menuNOSTALGIC.clicked == true || menuINTROSPECTIVE.clicked == true || menuLOST.clicked == true || menuDETERMINED.clicked == true) {
            
            if (menuNOSTALGIC.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadenostalgic.mp4");
                
                songMood = "nostalgic";
                moodSelected = 1;
                
                introspective[randomIntrospective].closeMovie();
                lost[randomLost].closeMovie();
                determined[randomDetermined].closeMovie();
                
                if(fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
            
            if (menuINTROSPECTIVE.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadeintrospective.mp4");
                
                songMood = "introspective";
                moodSelected = 2;
                
                nostalgic[randomNostalgic].closeMovie();
                lost[randomLost].closeMovie();
                determined[randomDetermined].closeMovie();
                
                if (fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
            
            if (menuLOST.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadelost.mp4");
                
                songMood = "lost";
                moodSelected = 3;
                
                nostalgic[randomNostalgic].closeMovie();
                introspective[randomIntrospective].closeMovie();
                determined[randomDetermined].closeMovie();
                
                if (fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
            
            if (menuDETERMINED.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadedetermined.mp4");
                
                songMood = "determined";
                moodSelected = 4;
                
                nostalgic[randomNostalgic].closeMovie();
                introspective[randomIntrospective].closeMovie();
                lost[randomLost].closeMovie();
                
                if (fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
        }
    }
    
}

void testApp::playSong(string song) {
    
    if (fadeOutVid.getIsMovieDone()) {
    
        if (firstTimeFaded == true) {
    
            activeSong.unloadSound();
            
            chosenSong = "sound/" + song + "0" + randomSong() + ".mp3";
            
            activeSong.loadSound(chosenSong);
            activeSong.play();
            
            firstTimeFaded = false;
        }
    }

}

void testApp::playDetermined() {
    
    if (activeSong.getPosition() < 1.0 && determined[randomDetermined].getIsMovieDone() == true) {
        
        determined[randomDetermined].closeMovie();
        string tempClip = ofToString(randomDetermined+1);
        determined[randomDetermined].loadMovie("movies/Determined/determined" + tempClip + ".mp4");
        randomDetermined = ofRandom(0,NDETERMINED);
        determined[randomDetermined].play();
        determined[randomDetermined].setLoopState(OF_LOOP_NONE);
        
    }
    
    else {
        cout << randomDetermined << " | " << determined[randomDetermined].isLoaded() << endl;
        determined[randomDetermined].draw(0,0);
        
    }

}

void testApp::playLost() {
    
    if (activeSong.getPosition() < 1.0 && lost[randomLost].getIsMovieDone() == true) {
        
        lost[randomLost].closeMovie();
        string tempClip = ofToString(randomLost+1);
        lost[randomLost].loadMovie("movies/Lost/lost" + tempClip + ".mp4");
        randomLost = ofRandom(0,NLOST);
        lost[randomLost].play();
        lost[randomLost].setLoopState(OF_LOOP_NONE);
        
    }
    
    else {
        cout << randomLost << " | " << lost[randomLost].isLoaded() << endl;
        lost[randomLost].draw(0,0);
        
    }
    
}

void testApp::playNostalgic() {
    
    if (activeSong.getPosition() < 1.0 && nostalgic[randomNostalgic].getIsMovieDone() == true) {
        
        nostalgic[randomNostalgic].closeMovie();
        string tempClip = ofToString(randomNostalgic+1);
        nostalgic[randomNostalgic].loadMovie("movies/Nostalgic/nostalgic" + tempClip + ".mp4");
        randomNostalgic = ofRandom(0,NNOSTALGIC);
        nostalgic[randomNostalgic].play();
        nostalgic[randomNostalgic].setLoopState(OF_LOOP_NONE);
        
    }
    
    else {
        cout << randomNostalgic << " | " << nostalgic[randomNostalgic].isLoaded() << endl;
        nostalgic[randomNostalgic].draw(0,0);
        
    }
    
}

void testApp::playIntrospective() {
    
    if (activeSong.getPosition() < 1.0 && introspective[randomIntrospective].getIsMovieDone() == true) {
        
        introspective[randomIntrospective].closeMovie();
        string tempClip = ofToString(randomIntrospective+1);
        introspective[randomIntrospective].loadMovie("movies/Introspective/introspective" + tempClip + ".mp4");
        randomIntrospective = ofRandom(0,NINTROSPECTIVE);
        introspective[randomIntrospective].play();
        introspective[randomIntrospective].setLoopState(OF_LOOP_NONE);
        
    }
    
    else {
        cout << randomIntrospective << " | " << introspective[randomIntrospective].isLoaded() << endl;
        introspective[randomIntrospective].draw(0,0);
    }
    
}

string testApp::randomSong(){
    
    float randomFloat = ofRandom(1, 5);
    int randomInt  = randomFloat;
    
    string result = ofToString(randomInt);
    
    return result;
    
}

void testApp::updateVideos() {
    
    if (activeSong.getIsPlaying()) {
        switch (moodSelected) {
                
            case 1 :
                nostalgic[randomNostalgic].update();
                break;
                
            case 2 :
                introspective[randomIntrospective].update();
                break;
                
            case 3 :
                lost[randomLost].update();
                break;
                
            case 4 :
                determined[randomDetermined].update();
                break;
        }
    }
    
}

void testApp::loadVideos() {
    
    for (int i=0; i<NDETERMINED; i++) {
        
        string tempClip = ofToString(i+1);
        
        determined[i].loadMovie("movies/Determined/determined" + tempClip + ".mp4");
        
    }
    
    for (int i=0; i<NLOST; i++) {
        
        string tempClip = ofToString(i+1);
        
        lost[i].loadMovie("movies/Lost/lost" + tempClip + ".mp4");
        
    }
    
    for (int i=0; i<NNOSTALGIC; i++) {
        
        string tempClip = ofToString(i+1);
        
        nostalgic[i].loadMovie("movies/Nostalgic/nostalgic" + tempClip + ".mp4");
        
    }
    
    for (int i=0; i<NINTROSPECTIVE; i++) {
        
        string tempClip = ofToString(i+1);
        
        introspective[i].loadMovie("movies/Introspective/introspective" + tempClip + ".mp4");
        
    }
    
    randomDetermined = ofRandom(0,NDETERMINED);
    randomLost = ofRandom(0,NLOST);
    randomNostalgic = ofRandom(0,NNOSTALGIC);
    randomIntrospective = ofRandom(0,NINTROSPECTIVE);
    
}