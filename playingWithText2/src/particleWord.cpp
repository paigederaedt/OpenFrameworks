

#include "particleWord.h"


//------------------------------------------------------------
void particleWord::draw(){
    ttfword.loadFont("Lekton-Regular.ttf", 32);
    ttfword.drawString(word, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    
}