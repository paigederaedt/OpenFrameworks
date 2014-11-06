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
    
    creature1.pos.x = 100;
    creature1.pos.y = 50;
    creature1.radius = 50;
    
    creature2.pos.x = 100;
    creature2.pos.y = 50;
    creature2.catchUpSpeed = 0.06f;
    creature2.radiusMult = 40;
    creature2.noiseFactor = 15.0f;
    creature2.colorR = 176;
    creature2.colorG = 196;
    creature2.colorB = 222;
    creature2.transPos.set(150,100);
    creature2.trailPos.set(5,5);
    
    creature2.pos.x = 100;
    creature2.pos.y = 50;
    creature3.catchUpSpeed = 0.04f;
    creature3.radiusMult = 30;
    creature3.noiseFactor = 30.0f;
    creature3.colorR = 255;
    creature3.colorG = 127;
    creature3.colorB = 80;
    creature3.transPos.set(50,150);
    creature3.trailPos.set(5,5);
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
	creature1.xenoToPoint(mouseX, mouseY);
    creature2.xenoToPoint(mouseX, mouseY);
    creature3.xenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    creature1.draw();
    creature2.draw();
    creature3.draw();
    
    
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
