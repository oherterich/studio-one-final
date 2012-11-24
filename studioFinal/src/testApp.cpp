#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    
    ofSetFrameRate(30);
    
    ofSetColor(255,255,255);
    
    firstTimeFaded = true; 
    
    howareyou.loadMovie("movies/howareyou.mp4");
    howareyou.play();
    
    
    menuNOSTALGIC.setup(30,385,135,25,"menunostalgic");
    menuINTROSPECTIVE.setup(45,430,110,25, "menuintrospective");
    menuLOST.setup(25,475, 100, 25,"menulost");
    menuDETERMINED.setup(15,520,115,20, "menudetermined");
    
    cout << fadeOutVid.getIsMovieDone() << " | " << firstTimeFaded << endl;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    howareyou.update();
    
    menuNOSTALGIC.update();
    menuINTROSPECTIVE.update();
    menuLOST.update();
    menuDETERMINED.update();
    
    fadeOutVid.update();
    
    playSong(songMood);
    
    ofSoundUpdate();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    howareyou.draw(0,0);
    
    menuNOSTALGIC.draw();
    menuINTROSPECTIVE.draw();
    menuLOST.draw();
    menuDETERMINED.draw();
    
    fadeOutVid.draw(0,0);
    
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
                
                if(fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
            
            if (menuINTROSPECTIVE.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadeintrospective.mp4");
                
                songMood = "introspective";
                
                if (fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
            
            if (menuLOST.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadelost.mp4");
                
                songMood = "lost";
                
                if (fadeOutVid.isLoaded()) {
                    fadeOutVid.play();
                    
                    fadeOutVid.setLoopState(OF_LOOP_NONE);
                }
            }
            
            if (menuDETERMINED.clicked == true) {
                
                fadeOutVid.closeMovie();
                
                fadeOutVid.loadMovie("movies/fadedetermined.mp4");
                
                songMood = "determined";
                
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

string testApp::randomSong(){
    
    float randomFloat = ofRandom(1, 5);
    int randomInt  = randomFloat;
    
    string result = ofToString(randomInt);
    
    return result;
    
}