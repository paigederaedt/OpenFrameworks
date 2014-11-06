#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    for (int i = 0; i < partWords.size(); i++){
        partWords[i].setInitialCondition(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0,0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    
    for (int i = 0; i < partWords.size(); i++){
        partWords[i].resetForce();
        
        
        partWords[i].addAttractionForce(mouseX, mouseY, 1000, 0.6);
        partWords[i].addRepulsionForce(mouseX, mouseY, 60, 1);
        
        
        partWords[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
        partWords[i].addClockwiseForce(mouseX, mouseY, 200, 1);
        
        partWords[i].addForce(0,0.04);  // gravity
        partWords[i].addDampingForce();
        partWords[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < partWords.size(); i++){
        partWords[i].draw();
        cout << "Word: " << i << " " << partWords[i].word << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    particleWord temp;
    //temp.pos.x = mouseX;
    //temp.pos.y = mouseY;
    
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        typeStr = typeStr.substr(0, typeStr.length()-1);
    }
    else if(key == OF_KEY_RETURN){
        temp.word = typeStr;
        partWords.push_back(temp);
        typeStr.clear();
        
    }else{
        if( bFirst ){
            typeStr.clear();
            bFirst = false;
        }
        typeStr.append(1, (char)key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
