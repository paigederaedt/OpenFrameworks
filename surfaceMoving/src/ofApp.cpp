#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int w = 100;
    int h = 100;
    
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            mesh.addVertex(ofPoint((x - w / 2) * 6,(y - h / 2) * 6,0));
            mesh.addColor(ofColor(0,0,0));
        }
    }
    
    for (int y = 0; y < h - 1; y++){
        for (int x = 0; x < w - 1; x++){
            int i1 = x + w * y;
            int i2 = x + 1 + w * y;
            int i3 = x + w * (y + 1);
            int i4 = x + 1 + w * (y + 1);
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i4, i3);
        }
    }
    
    //setNormals(mesh);
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int w = 100;
    int h = 100;
    
    float time = ofGetElapsedTimef();

    
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            int i = x + w * y;
            ofPoint p = mesh.getVertex(i);
            float value = ofNoise(x * 0.2, y * 0.2, time * 0.5);
            p.z = value * 100;
            mesh.setVertex(i, p);
            mesh.setColor(i, ofColor(value * 255, value * 255, value * 255));
        }
    }
    //setNormals(mesh);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    ofBackground(ofColor(0));
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    
    float time = ofGetElapsedTimef();
    float angle = time * 20;
    ofRotate(30, 1, 0, 0);
    ofRotate(angle, 0, 0, 1);
    
    mesh.draw();
    ofPopMatrix();
    
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

//--------------------------------------------------------------
void setNormals(ofMesh &mesh){
    
    int nV = mesh.getNumVertices();
    int nT = mesh.getNumIndices();
    vector <ofPoint> norm(nV);
    for (int t = 0; t < nT; t++){
        int i1 = mesh.getIndex(3 * t);
        int i2 = mesh.getIndex(3 * t + 1);
        int i3 = mesh.getIndex(3 * t + 2);
        
        const ofPoint &v1 = mesh.getVertex(i1);
        const ofPoint &v2 = mesh.getVertex(i2);
        const ofPoint &v3 = mesh.getVertex(i3);
        
        ofPoint dir = ((v2 - v1).crossed(v3 - v1)).normalized();
        
        norm[i1] += dir;
        norm[i2] += dir;
        norm[i3] += dir;
    }
    
    for (int i = 0; i < nV; i++){
        norm[i].normalize();
    }
    
    mesh.clearNormals();
    mesh.addNormals(norm);
}
