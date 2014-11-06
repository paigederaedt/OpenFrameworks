#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofBackground(0,0,0);
    
    ofSetCircleResolution(100);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float xorig = ofGetWidth() / 2;
    float yorig = ofGetHeight() / 2;
    int numOfCircles = 100;
    float space = ofMap(sin(ofGetMouseX()),-1,1,0,ofGetHeight() / 2);
    
    for (int i = 0; i < numOfCircles; i++){
        float angle = (TWO_PI / numOfCircles) * i;
        float x = xorig + space * cos(angle);
        float y = yorig + space * sin(angle);
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
        ofCircle(x,y,2);
    }
    
    
    float radius = 50;
    float angle2 = ofGetMouseX();
    int numOfRectangles = 10;
    for (int j = 0; j < numOfRectangles; j++){
        float angle1 = (TWO_PI / numOfRectangles) * j;
        float xorig1 = xorig + space * cos(angle1);
        float yorig1 = yorig + space * sin(angle1);
        float x = xorig1 + radius * cos(angle2);
        float y = yorig1 + radius * -sin(angle2);
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
        ofRect(x,y,5,5);
    }
    
    float x1 = 0;
    float y1 = 0;
    float x2 = x1 + ofMap(sin(ofGetMouseX()),-1,1,0,ofGetHeight() / 2);
    float y2 = y1;
    float x3 = x1;
    float y3 = y1 + ofMap(sin(ofGetMouseX()),-1,1,0,ofGetHeight() / 2);
    int numofTriangles = 50;
    for (int k = 0; k < numofTriangles; k++){
        ofPushMatrix();
        ofTranslate(ofGetWidth(), ofGetHeight());
        ofRotateZ(ofMap(sin(ofGetMouseX()),-1,1,0,360));
        ofTriangle(x1,y1,x2,y2,x3,y3);
        ofPushMatrix();
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255),75);
    }
    
    
    
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

