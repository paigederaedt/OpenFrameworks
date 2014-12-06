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
    
    ofFill();
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    float angle = ofGetElapsedTimef() * 3.2;
    float strength = (sin(angle + .45)) * .5f * 5.f;
    ofVec3f faceNormal;
    for(int i = 0; i < triangles.size(); i++) {
        // store the face normal here.
        // we change the vertices, which makes the face normal change
        // every time that we call getFaceNormal //
        faceNormal = triangles[i].getFaceNormal();
        for(int j = 0; j < 2; j++) {
            triangles[i].setVertex( j, triangles[i].getVertex(j) + faceNormal * strength);
        }
    }
    sphere.getMesh().setFromTriangles(triangles);
    
//    
//    float rad = ofMap(sin(ofGetElapsedTimef()), -1, 1, 2, 5);
//    
//    cam.begin();
//    ofPushMatrix();
//    //ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//    ofRotate(spinX, 1.0, 0.0, 0.0);
//    ofRotate(spinY, 0, 1.0, 0.0);
//    mesh = sphere.getMesh();
//    for (int i = 0; i < mesh.getVertices().size(); i++){
//        mesh.addColor(ofColor(255,102,102));
//        ofPoint point = mesh.getVertices()[i];
//        ofCircle(point.x, point.y, point.z, rad);
//    }
//    ofPopMatrix();
//    cam.end();

    sphere.drawVertices();
    
    
    //mesh.draw();
    

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
