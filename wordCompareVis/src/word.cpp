#include "ofMain.h"
#include "word.h"

void word::setup(){
    
    ttfword.loadFont("Lekton-Regular.ttf", 20);
}

void word::draw(){
    
    ofSetColor(255,0,0);
}

word::word(){
    
    pos.set(0,0);
}
