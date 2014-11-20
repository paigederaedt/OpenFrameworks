#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    myImg.allocate(800,600, OF_IMAGE_GRAYSCALE);
    
    //
    // detroit!
    //    unsigned char * pixels = myImg.getPixels();
    //    
    //    for (int i = 0; i < myImg.getWidth(); i++){
    //        for (int j = 0; j < myImg.getHeight(); j++){
    //            // pos = y * width + x
    //            pixels[ (int)(j * myImg.getWidth() + i)] =  (i % (j+1)) * 5.0;
    //        }
    //    }
    
    
    // disneyland !
//    ofPixels pix = myImg.getPixelsRef();   // ref = reference...
//    
//    for (int i = 0; i < myImg.getWidth(); i++){
//        for (int j = 0; j < myImg.getHeight(); j++){
//            pix.setColor(i,j, ofColor(127));
//        }
//    }
//    myImg.setFromPixels(pix);
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    unsigned char * pixels = myImg.getPixels();

    for (int i = 0; i < myImg.getWidth(); i++){
        for (int j = 0; j < myImg.getHeight(); j++){
            
            float distance = ofDist(i, j, mouseX, mouseY);
            if (distance < 25){
                pixels[ (int)(j * myImg.getWidth() + i)] = 255;
            }
            
            
            pixels[ (int)(j * myImg.getWidth() + i)] = pixels[ (int)(j * myImg.getWidth() + i)] -1;
            //else {
            //    pixels[ (int)(j * myImg.getWidth() + i)] = 0;
           // }
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
