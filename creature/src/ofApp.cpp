#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    
    ofSetVerticalSync(true);
    
    // set background:
    
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    
    // set the position of the rectangle:
    
    myCreature.pos.x = 100;
    myCreature.pos.y = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
	myCreature.xenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    myCreature.draw();
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
