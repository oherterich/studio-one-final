#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0,0,0);
    
    ofSetColor(255,255,255);
    howareyou.loadMovie("movies/howareyou.mp4");
    howareyou.play();
    
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
    
    ofSoundUpdate();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    howareyou.draw(0,0);
    menuNOSTALGIC.draw();
    menuINTROSPECTIVE.draw();
    menuLOST.draw();
    menuDETERMINED.draw();
    
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
        
        activeSong.unloadSound();
        
        chosenSong = "sound/nostalgic01.mp3";
        
        activeSong.loadSound(chosenSong);
        activeSong.play();
    }
    
    menuINTROSPECTIVE.checkClick(x,y);
    if (menuINTROSPECTIVE.clicked == true) {
        menuNOSTALGIC.clicked = false;
        menuLOST.clicked = false;
        menuDETERMINED.clicked = false;
        
        activeSong.unloadSound();
        
        chosenSong = "sound/introspective01.mp3";
        
        activeSong.loadSound(chosenSong);
        activeSong.play();
    }
    
    menuLOST.checkClick(x,y);
    if (menuLOST.clicked == true) {
        menuINTROSPECTIVE.clicked = false;
        menuNOSTALGIC.clicked = false;
        menuDETERMINED.clicked = false;
        
        activeSong.unloadSound();
        
        chosenSong = "sound/lost01.mp3";
        
        activeSong.loadSound(chosenSong);
        activeSong.play();
    }
    
    menuDETERMINED.checkClick(x,y);
    if (menuDETERMINED.clicked == true) {
        menuINTROSPECTIVE.clicked = false;
        menuLOST.clicked = false;
        menuNOSTALGIC.clicked = false;
        
        activeSong.unloadSound();
        
        chosenSong = "sound/determined01.mp3";
        
        activeSong.loadSound(chosenSong);
        activeSong.play();
    }
    
    
    
    if (menuNOSTALGIC.clicked == true || menuINTROSPECTIVE.clicked == true || menuLOST.clicked == true || menuDETERMINED.clicked == true) {
        howareyou.closeMovie();
    }
}