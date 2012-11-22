#include "menu.h"

Menu::Menu(){
    int posX;
    int posY;
    int width;
    int height;
    
    bool clicked;
    
    string clipName;
}

void Menu::setup(int _posX, int _posY, int _width, int _height, string _clipName){
    
    posX = _posX;
    posY = _posY;
    width = _width;
    height = _height;
    
    clicked = false;
    
    clipName = _clipName;
    
}

void Menu::update(){
    
    if (clicked == true) {

        menuVideo.update();
    }
    
}

void Menu::draw(){
    
    if (clicked == true) {
        menuVideo.draw(0,0);
    }

}

void Menu::checkClick(int x, int y){
    
    if (clicked == false) {
        menuVideo.closeMovie();
    }
    
    if (x > posX && x < posX + width && y > posY && y < posY + height) {
        
        clicked = true;

        menuVideo.loadMovie("movies/" + clipName +".mp4");
        menuVideo.play();
        
    }
    
    

}