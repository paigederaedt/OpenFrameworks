#include "creature.h"


//------------------------------------------------------------------
creature::creature(){
    catchUpSpeed = 0.03f;
    
    pos.set(0,0);
    prevPos.set(0,0);
}

//------------------------------------------------------------------
void creature::draw() {
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y, 0);
    ofRotateZ(angle * RAD_TO_DEG);
    ofBeginShape();
    for (int i = 0; i < 100; i++){
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
        float add = ofNoise(i/10.0f, ofGetElapsedTimef() * 3 * (float)ofGetMouseX() / (float)ofGetWidth());
        
        ofVertex( (50 + 100 * add) * cos((i / 100.0) * TWO_PI),
                 (50 + 100 * add) * sin((i / 100.0) * TWO_PI));
    }
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(pos.x + 150, pos.y + 150, 0);
    ofRotateZ(angle * RAD_TO_DEG);
    ofBeginShape();
    for (int i = 0; i < 100; i++){
        ofSetColor(ofRandom(255),ofRandom(255),255);
        float add = ofNoise(i/15.0f, ofGetElapsedTimef() * 3 * (float)ofGetMouseY()/ (float)ofGetWidth());
        
        ofVertex(	(50 * add) * cos((i / 100.0) * TWO_PI),
                 (50 * add) * sin((i / 100.0) * TWO_PI));
    }
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(pos.x + 150, pos.y + 50, 0);
    ofRotateZ(angle * RAD_TO_DEG);
    ofBeginShape();
    for (int i = 0; i < 100; i++){
        ofSetColor(ofRandom(255),255,ofRandom(255));
        float add = ofNoise(i/30.0f, ofGetElapsedTimef() * 3 * (float)ofGetMouseY()/ (float)ofGetWidth());
        
        ofVertex(	(20 * add) * cos((i / 100.0) * TWO_PI),
                 (20 * add) * sin((i / 100.0) * TWO_PI));
    }
    ofEndShape();
    ofPopMatrix();
    
}

//------------------------------------------------------------------
void creature::xenoToPoint(float catchX, float catchY){
    
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    
    angle = atan2(dy, dx);
    
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
    
}
