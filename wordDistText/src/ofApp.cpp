#include "ofApp.h"

// comparison routine for sort...
bool comparisonFunction( particleWord * a, particleWord * b) {
    return a->pos.x < b->pos.x;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ttf.loadFont("Lekton-Regular.ttf", 100);
    
    string fileContents = ofFile("golddigger.txt").readToBuffer();
    vector <string> lyrics = ofSplitString(fileContents, " ");
    
    
    for (int i = 0; i < lyrics.size(); i++){
        particleWord * temp = new particleWord();
        temp->word = lyrics[i];
        temp->ttfword = &ttf;
        temp->setup();
        partWords.push_back(temp);
        
        //cout << lyrics[i] << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    sort(partWords.begin(), partWords.end(), comparisonFunction );
    
    for (int i = 0; i < partWords.size(); i++){
        partWords[i]->resetForce();
    }
    
    for (int i = 0; i < partWords.size(); i++){
        
        partWords[i]->addRepulsionForce(mouseX, mouseY, 1000, 0.08f);
        
        
        for (int j = 0; j < i; j++){
            if (partWords[i]->getLevDistScale(*partWords[j]) <= 0.02){
                partWords[i]->addRepulsionForce(*partWords[j], 500, partWords[i]->getLevDistScale(*partWords[j]));
            } else {
                partWords[i]->addAttractionForce(*partWords[j], 500, partWords[i]->getLevDistScale(*partWords[j]));
            }
            //cout << "word one: " << partWords[i]->word << " word two: " << partWords[j]->word << " "
                //<< partWords[i]->getLevDistScale(*partWords[j]) << endl;
            partWords[i]->addCounterClockwiseForce(*partWords[j], 100, 0.05f);
        }
    }
    
    for (int i = 0; i < partWords.size(); i++){
        partWords[i]->addDampingForce();
        partWords[i]->bounceOffWalls();
        partWords[i]->update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < partWords.size(); i++){
        partWords[i]->draw();
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
