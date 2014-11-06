#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < partWords.size(); i++){
        partWords[i].draw();
        cout << "Word: " << i << " " << partWords[i].word << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    particleWord temp;
    temp.pos.x = mouseX;
    temp.pos.y = mouseY;
    
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        typeStr = typeStr.substr(0, typeStr.length()-1);
    }
    else if(key == OF_KEY_RETURN){
        temp.word = typeStr;
        partWords.push_back(temp);
        typeStr.clear();
        
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
