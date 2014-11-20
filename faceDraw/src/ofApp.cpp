#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    face.loadImage("face.jpg");
    face.setImageType(OF_IMAGE_GRAYSCALE);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    face.draw(face.getWidth(),0);
    
    
    unsigned char * pix = face.getPixels();
    
    
    for (int i = 0; i < face.getWidth(); i+=10){
        for (int j = 0; j < face.getHeight(); j+=10){
            
            int bri = pix[ (int)(j * face.getWidth() + i)];
            
            //float radius = ofMap(bri, 0, 255, 3, 3.6);
            //ofCircle(i,j, radius);
            
            float angle = ofMap(bri, 0, 255, 0, mouseX);
            
            ofPushMatrix();
            ofTranslate(i, j);
            ofRotate(angle);
            ofRect(0,0,10, 2);
            
            ofPopMatrix();
            
            
            //ofSetColor(bri);
            //ofRect(i,j, 10, 10);
            
        }
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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
