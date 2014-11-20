#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    myImg.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_GRAYSCALE);
//    
//    //detroit way
//    unsigned char * pixels = myImg.getPixels();
//    for (int i = 0; i < myImg.getWidth(); i++){
//        for (int j = 0; j < myImg.getHeight(); j++){
//            //pos = y * width + x
//            //pixels[(int)(j * myImg.getWidth() + i)] = sin(i/30) * 255 + cos(j/30) * 255;
//            pixels[(int)(j * myImg.getWidth() + i)] = sin(i % 10) * 255 + tan(j % 10) * 255;
//        }
//    }
//    
//    myImg.update();
}

//--------------------------------------------------------------
void ofApp::update(){

    myImg.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_GRAYSCALE);
    
    //detroit way
    unsigned char * pixels = myImg.getPixels();
    for (int i = 0; i < myImg.getWidth(); i++){
        for (int j = 0; j < myImg.getHeight(); j++){
            //pos = y * width + x
            //pixels[(int)(j * myImg.getWidth() + i)] = sin(i/30) * 255 + cos(j/30) * 255;
            pixels[(int)(j * myImg.getWidth() + i)] = sin(i % 50) * mouseY + tan(j % 50) * mouseX;
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
