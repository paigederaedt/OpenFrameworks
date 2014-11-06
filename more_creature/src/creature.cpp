#include "creature.h"


//------------------------------------------------------------------
creature::creature(){
    catchUpSpeed = 0.03f;
    
    pos.set(0,0);
    prevPos.set(0,0);
    
    radius = 0;
    radiusMult = 100;
    transPos.set(0,0);
    colorR = 102;
    colorG = 205;
    colorB = 170;
    noiseFactor = 10.0f;
    trailPos.set(15,15);
    lenVel = 0;
    

    
    
}

//------------------------------------------------------------------
void creature::draw() {
    
    ofPushMatrix();
    ofTranslate(pos.x + transPos.x, pos.y + transPos.y, 0);
    ofRotateZ(angle * RAD_TO_DEG);
    ofBeginShape();
    for (int i = 0; i < 100; i++){
        ofSetColor(colorR,colorG,colorB);
        float add = ofNoise(i/noiseFactor, ofGetElapsedTimef() * 2 * (float)ofGetMouseX() / (float)ofGetWidth());
        float breath = ofMap(sin(lenVel),-1,1,-50,0);
        float v1 = (radius + breath + radiusMult * add) * cos((i / 100.0) * TWO_PI);
        float v2 = (radius + breath + radiusMult * add) * sin((i / 100.0) * TWO_PI);
        ofVertex( v1, v2);
        ofCircle(v1 - trailPos.x, v2 - trailPos.y, 2);
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
    lenVel = ofDist(0, 0, dx, dy);
    
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
    
}
