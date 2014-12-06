#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sphere.setRadius(300);
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofBackground(0);
    ofBackgroundGradient(20, 0, OF_GRADIENT_CIRCULAR);
    ofEnableDepthTest();
    
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    
    sphere.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    sphere.setMode(OF_PRIMITIVE_TRIANGLES);
    triangles = sphere.getMesh().getUniqueFaces();
    
    cam.begin();


    ofFill();
    ofSetColor(255,255,255);
    mesh = sphere.getMesh();
    int index = (int)ofMap(sin(ofGetElapsedTimef() * 80), -1, 1, 0, mesh.getVertices().size());
    int rand = (int)ofMap(mouseX, 0, ofGetWidth(), 0, mesh.getVertices().size());
    for (int i = 0; i < mesh.getVertices().size(); i++){
        ofPoint p1 = mesh.getVertices()[index];
        //ofPoint p1 = mesh.getVertices()[i];
        ofPoint p2 = mesh.getVertices()[rand];
        ofLine(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
    }

    cam.end();
    
    
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
