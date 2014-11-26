#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    myNode.setGlobalPosition( ofPoint(ofGetWidth()/2,ofGetHeight()/2,400));
    myNode2.setParent(myNode);
    myNode2.setPosition(100,0,0);
    myNode3.setParent(myNode2);
    myNode3.setPosition(0,100,0);
    myNode4.setParent(myNode3);
    myNode4.setPosition(0,0,100);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myNode.setGlobalPosition( ofPoint(0, 0, 0));
    myNode.pan(1.0);
    myNode2.setPosition(50 + 50 * sin(ofGetElapsedTimef()),0,0);
    myNode2.tilt(1.7);
    myNode3.setPosition(0,20 + 90 * cos(ofGetElapsedTimef()),0);
    myNode3.tilt(0.4);
    
    line.addVertex(myNode4.getGlobalPosition());
    if (line.size() > 1000){
        line.getVertices().erase(line.getVertices().begin());
    }
    //myNode.lookAt( ofPoint(mouseX, mouseY, 0));
    
    line2.addVertex(myNode3.getGlobalPosition());
    if (line.size() > 1000){
        line.getVertices().erase(line.getVertices().begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    //ofPushMatrix();
    
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofRotateX(mouseX);
    
    cam.begin();
    ofEnableDepthTest();
//    myNode.draw();
//    myNode2.draw();
//    myNode3.draw();
//    myNode4.draw();
    
    //drawing something else
//    ofMatrix4x4 mat = myNode3.getGlobalTransformMatrix();
//    ofPushMatrix();
//    ofMultMatrix(mat);
//    ofCircle(0,0,100);
//    ofPopMatrix();
    
    
    //ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    line.draw();
    ofSetColor(0,255,0);
    line2.draw();
    cam.end();
    
    //ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
