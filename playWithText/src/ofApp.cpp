#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.loadFont("Lekton-Regular.ttf", 32);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    myFont.drawString(typeStr, mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        typeStr = typeStr.substr(0, typeStr.length()-1);
    }
    else if(key == OF_KEY_RETURN ){
        typeStr += "\n";
    }else{
        if( bFirst ){
            typeStr.clear();
            bFirst = false;
        }
        typeStr.append(1, (char)key);
    }
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
