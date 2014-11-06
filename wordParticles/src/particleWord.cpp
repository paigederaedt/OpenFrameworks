

#include "particleWord.h"
#include "ofMain.h"


//------------------------------------------------------------
void particleWord::draw(){
    ttfword.drawString(word, pos.x, pos.y);
}


//------------------------------------------------------------
particleWord::particleWord(){
    setInitialCondition(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0,0);
    damping = 0.05f;
    ttfword.loadFont("Lekton-Regular.ttf", 12);
}

//------------------------------------------------------------
void particleWord::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particleWord::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particleWord::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}


//------------------------------------------------------------
void particleWord::addRepulsionForce( float px, float py, float radius, float strength){
    
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x += diff.x * pct * strength;
        frc.y += diff.y * pct * strength;
    }
    
}

//------------------------------------------------------------
void particleWord::addAttractionForce( float px, float py, float radius, float strength){
    
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x -= diff.x * pct * strength;
        frc.y -= diff.y * pct * strength;
    }
    
}


//------------------------------------------------------------
void particleWord::addClockwiseForce( float px, float py, float radius, float strength){
    
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x -= diff.y * pct * strength;
        frc.y += diff.x * pct * strength;
    }
    
}

//------------------------------------------------------------
void particleWord::addCounterClockwiseForce( float px, float py, float radius, float strength){
    
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x += diff.y * pct * strength;
        frc.y -= diff.x * pct * strength;
    }
    
}





//------------------------------------------------------------
void particleWord::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

//------------------------------------------------------------
void particleWord::update(){
    vel = vel + frc;
    pos = pos + vel;
}
