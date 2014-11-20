#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    face.loadImage("face.jpg");
    face.setImageType(OF_IMAGE_GRAYSCALE);
    
    face2.allocate(face.getWidth(), face.getHeight(), OF_IMAGE_GRAYSCALE);
    
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
//    unsigned char * facePixels = face.getPixels();
//    unsigned char * face2Pixels = face2.getPixels();
//    
//    //    for (int i = 0; i < face.getWidth() * face.getHeight(); i++){
//    //        face2Pixels[i] = 255 - facePixels[i];
//    //    }
//    
//    
//    for (int i = 0; i < face.getWidth(); i++){
//        for (int j = 0; j < face.getHeight(); j++){
//            
//            int pos = j * face.getWidth() + i;
//            int pos2 = (j ) * face.getWidth() + (i + ofRandom(-mouseX,mouseX));
//            if (pos2 < 0) pos2 = 0;
//            if (pos2 >= face.getWidth()* face.getHeight()) pos2 = face.getWidth()* face.getHeight()-1 ;
//            
//            
//            face2Pixels[pos] = facePixels[pos2];
//        }
//    }
//    
//    
//    
//    face2.update();
    
    unsigned char * facePixels = face.getPixels();
    unsigned char * face2Pixels = face2.getPixels();

    for (int i = 0; i < face.getWidth() * face.getHeight(); i++){
        
        if (facePixels[i] > mouseX){
            face2Pixels[i] = 255;
        } else {
            face2Pixels[i] = 0;
        }
        //face2Pixels[i] =
    }
    
    face2.update();

    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    face.draw(0,0);
    face2.draw(face.getWidth() + 10, 0);
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
