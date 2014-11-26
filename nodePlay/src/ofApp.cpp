#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i < 10; i++){
        ofNode tempNode;
        tempNode.setGlobalPosition(ofGetWidth() / 2 + ofRandom(100), ofGetHeight() / 2 + ofRandom(100), ofRandom(100));
        nodes.push_back(tempNode);
    }
    
    for (int i = 1; i < nodes.size(); i++){
        nodes[i].setParent(nodes[i - 1]);
    }
    
//    myNode.setGlobalPosition( ofPoint(ofGetWidth()/2,ofGetHeight()/2,400));
//    myNode2.setParent(myNode);
//    myNode2.setPosition(100,0,0);
//    myNode3.setParent(myNode2);
//    myNode3.setPosition(0,100,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    myNode.setGlobalPosition( ofPoint(0, 0, 0));
//    myNode.pan(1.0);
//    myNode2.setPosition(50 + 50 * sin(ofGetElapsedTimef()),0,0);
//    myNode2.tilt(1.7);
    
    for (int i = 0; i < nodes.size() - 1; i++){
        ofNode node = nodes[i];
        node.setGlobalPosition(ofPoint(0,0,0));
        //node.pan(1.0);
        nodes[i + 1].setPosition(40 * sin(ofGetElapsedTimef()),0,0);
        //node.tilt(1.7);
        
    }
    
    line.addVertex(nodes[3].getGlobalPosition());
    if (line.size() > 1000){
        line.getVertices().erase(line.getVertices().begin());
    }
    //myNode.lookAt( ofPoint(mouseX, mouseY, 0));
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
    
    //drawing something else
    //    ofMatrix4x4 mat = myNode3.getGlobalTransformMatrix();
    //    ofPushMatrix();
    //    ofMultMatrix(mat);
    //    ofCircle(0,0,100);
    //    ofPopMatrix();
    
    
    line.draw();
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
