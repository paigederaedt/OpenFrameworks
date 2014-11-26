#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    image.loadImage("chauhanfam.jpg");
    image.resize(200,200);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float intensityThreshold = 150.0;
    for (int x = 0; x < image.getWidth(); ++x){
        for (int y = 0; y < image.getHeight(); ++y){
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold){
                float saturation = c.getSaturation();
                float z = ofMap(saturation,0,255,-100,100);
                ofVec3f pos(4 * x,4 * y,z);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }
    
    float connectionDistance = 30.0;
    int numVerts = mesh.getNumVertices();
    for (int a = 0; a < numVerts; ++a){
        ofVec3f verta = mesh.getVertex(a);
        for (int b = a + 1; b < numVerts; ++b){
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance){
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    
    cout << mesh.getNumVertices() << endl;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofColor centerColor = ofColor(85,78,68);
    ofColor edgeColor = (0,0,0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
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
