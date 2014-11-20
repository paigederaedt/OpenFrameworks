#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("gradient");
    
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetFrameNum() % 30 == 0){
        shader.load("gradient");
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    shader.begin();
    shader.setUniform1f("mousex", mouseX);
    shader.setUniform1f("mousey", mouseY);
    
    ofRect(100,100, 400,400);
    shader.end();
    
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
