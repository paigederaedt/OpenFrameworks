#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    myImage.loadImage("imgres.jpg");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
    myImageThreshold.allocate(myImage.getWidth(), myImage.getHeight(), OF_IMAGE_GRAYSCALE);
    
    unsigned char * pixorig = myImage.getPixels();
    unsigned char * pixthresh = myImageThreshold.getPixels();
    int white_count = 0;
    int black_count = 0;
    vector < ofPoint > white_pixels;
    vector < ofPoint > black_pixels;
    
    for (int i = 0; i < myImage.getWidth() * myImage.getHeight(); i++){
        if (pixorig[i] > 30){
            pixthresh[i] = 0;
            black_count++;
        } else {
            pixthresh[i] = 255;
            white_count++;
        }
    }
    myImageThreshold.update();
    
    for (int i = 0; i < myImageThreshold.getWidth(); i++){
        for (int j = 0; j < myImageThreshold.getHeight(); j++){
            if (pixthresh[(int)(j * myImageThreshold.getWidth() + i)] == 255){
                white_pixels.push_back(ofPoint(i, j));
            } else {
                black_pixels.push_back(ofPoint(i, j));
            }
        }
    }
    
    float total_x = 0;
    float total_y = 0;
    min_x = white_pixels[0].x;
    min_y = white_pixels[0].y;
    max_x = white_pixels[0].x;
    max_y = white_pixels[0].y;

    
    for (int i = 0; i < white_pixels.size(); i++){
        total_x += white_pixels[i].x;
        total_y += white_pixels[i].y;

        if (white_pixels[i].x < min_x){
            min_x = white_pixels[i].x;
        }
        if (white_pixels[i].x > max_x){
            max_x = white_pixels[i].x;
        }
        if (white_pixels[i].y < min_y){
            min_y = white_pixels[i].y;
        }
        if (white_pixels[i].y > max_y){
            max_y = white_pixels[i].y;
        }
        
    }
    
    avg_white_pixel = ofPoint(total_x / white_pixels.size(), total_y / white_pixels.size());
    
    cout << "# white pixels: " << white_count << endl;
    cout << "# black pixels: " << black_count << endl;
    cout << "avg white pixel pos: " << "(" << total_x / white_pixels.size() << ", " << total_y / white_pixels.size() << ")" << endl;
    cout << "bounding box: x1: " << min_x << " y1: " << min_y << " x2: " << max_x << " y2: " << max_y << endl;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);
    myImage.draw(0,0);
    myImageThreshold.draw(myImage.getWidth(),0);
    ofSetColor(0,255,128);
    ofCircle(avg_white_pixel.x + myImage.getWidth(), avg_white_pixel.y, 10);
    //ofRect(min_x + myImage.getWidth(), min_y, max_x - min_x, max_y - min_y);
    ofLine(min_x + myImage.getWidth(), min_y, min_x + myImage.getWidth(), max_y);
    ofLine(min_x + myImage.getWidth(), max_y, max_x + myImage.getWidth(), max_y);
    ofLine(max_x + myImage.getWidth(), max_y, max_x + myImage.getWidth(), min_y);
    ofLine(max_x + myImage.getWidth(), min_y, min_x + myImage.getWidth(), min_y);


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
