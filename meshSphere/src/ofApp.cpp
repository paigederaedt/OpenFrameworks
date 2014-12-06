#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sphere.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//    sphere.setRadius(100);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);

    
    sphere.setPosition(ofGetWidth()*.2, ofGetHeight()*.75, 0);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    
    // get all the faces from the icoSphere, handy when you want to copy
    // individual vertices or tweak them a little ;)
//    vector<ofMeshFace> triangles = sphere.getMesh().getUniqueFaces();
    
    // now draw
    sphere.draw();

//    sphere.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
//    float spinX = sin(ofGetElapsedTimef()*.35f);
//    float spinY = cos(ofGetElapsedTimef()*.075f);
//    sphere.rotate(spinX, 1.0, 0.0, 0.0);
//    sphere.rotate(spinY, 0, 1.0, 0.0);
//    triangles = sphere.getMesh().getUniqueFaces();
//    sphere.draw();
    
//
//    sphere.setPosition(ofGetWidth()*.8f, ofGetHeight()*.25, 0);
//    sphere.setRadius(200);
//
//    
//
//    sphere.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//
//        ofFill();
//        ofSetColor(255);
//            float angle = ofGetElapsedTimef()*3.2;
//            float strength = (sin( angle+.25 )) * .5f * 5.f;
//            ofVec3f faceNormal;
//            for(int i = 0; i < triangles.size(); i++ ) {
//                // store the face normal here.
//                // we change the vertices, which makes the face normal change
//                // every time that we call getFaceNormal //
//                faceNormal = triangles[i].getFaceNormal();
//                for(int j = 0; j < 3; j++ ) {
//                    triangles[i].setVertex( j, triangles[i].getVertex(j) + faceNormal * strength);
//                }
//            }
//            sphere.getMesh().setFromTriangles( triangles );
//    
//        sphere.draw();
    
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
