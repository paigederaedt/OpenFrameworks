#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

    myImg.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_GRAYSCALE);
    
    unsigned char * pixels = myImg.getPixels();
    for (int i = 0; i < myImg.getWidth(); i++){
        for (int j = 0; j < myImg.getHeight(); j++){
            //pos = y * width + x
            //pixels[(int)(j * myImg.getWidth() + i)] = mouseX % (i + 1) + mouseY % (j + 1);
            //pixels[(int)(j * myImg.getWidth() + i)] =  cos(mouseX % (i + 1)) +  sin(mouseY % (j + 1));
            int dist = ofDist(i, j, mouseX, mouseY);
            pixels[(int)(j * myImg.getWidth() + i)] =  cos(dist) * 255 + sin(dist) * 255;

        }
    }
    
    myImg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    myImg.draw(0,0);
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
