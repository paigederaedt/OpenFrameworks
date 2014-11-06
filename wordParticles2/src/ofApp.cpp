#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    startTime = 0.0f;
}

//--------------------------------------------------------------
void ofApp::update(){

    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    for (int i = 0; i < partWords.size(); i++){
        partWords[i].resetForce();
    }
    
    for (int i = 0; i < partWords.size(); i++){
        
        partWords[i].addAttractionForce(mouseX, mouseY, 1000, 0.09f);

        
        for (int j = 0; j < i; j++){
            partWords[i].addRepulsionForce(partWords[j], 200, 0.03);
            partWords[i].addCounterClockwiseForce(partWords[j], 80, 0.09);
        }
    }
    
    for (int i = 0; i < partWords.size(); i++){
        partWords[i].addDampingForce();
        partWords[i].bounceOffWalls();
        partWords[i].update();
    }
    
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
    
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        typeStr = typeStr.substr(0, typeStr.length()-1);
    }
    else if(key == OF_KEY_RETURN){
        temp.word = typeStr;
        temp.endTime = ofGetElapsedTimef();
        temp.size = temp.endTime - startTime;
        startTime = temp.endTime;
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
