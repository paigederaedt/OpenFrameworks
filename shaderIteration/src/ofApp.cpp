#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetFrameNum() % 60 == 0) shader.load("shader");
    shader.load("shader");
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void ofApp::draw(){

    shader.begin();
    shader.setUniform1f("mousex", mouseX);
    shader.setUniform1f("mousey", mouseY);
    shader.setUniform1f("time", ofGetElapsedTimef());
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
//    non shader example to see frame rate decrease
//    int numSquares = ofMap(mouseX, 0, ofGetWidth(), 10, ofGetWidth());
//    float squareSize = ofGetWidth() / numSquares;
//    
//    for (int x = 0; x < numSquares; x++){
//        for (int y = 0; y < numSquares; y++){
//            ofSetColor((x * y) % 255);
//            ofRect(x * squareSize, y * squareSize, squareSize, squareSize);
//        }
//    }
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
