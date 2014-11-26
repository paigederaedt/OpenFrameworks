

#include "particleWord.h"
#include "ofMain.h"

int levenshtein(string word1, string word2) {
    
    const char * stra = word1.c_str();
    const char * strb = word2.c_str();
    
    int i, j, k, l, m1, m2, m3, laa, r;
    int lengtha, lengthb, lengthmin;
    int **d;
    char *a;
    
    lengtha = strlen(stra);
    lengthb = strlen(strb);
    lengthmin = lengtha;
    if(lengthb > lengthmin) lengthmin = lengthb;
    
    a = (char*)malloc((lengthmin+2)*sizeof(char));
    d = (int**)malloc((lengthmin+2)*sizeof(int*));
    for(i = 0; i < lengthmin + 2; i++) d[i] = (int*)malloc((lengthmin+2)*sizeof(int));
    for(i = 0; i <= lengtha; i++) a[i] = stra[i];
    
    laa = lengtha;
    d[0][0] = 0;
    for(i = 1; i <= lengtha; i++) d[i][0] = d[i-1][0]+1;
    for(j = 1; j <= lengthb; j++) d[0][j] = d[0][j-1]+1;
    
    for(i = 1; i <= laa; i++) {
        for(j = 1;j <= lengthb; j++) {
            r = 0;
            if(a[i-1] != strb[j-1]) {
                r = 1;
                a[i-1] = strb[j-1];
            }
            m1 = d[i-1][j-1]+r;
            for(k = lengtha; k >= i-1; k--) a[k+1] = a[k];
            a[j-1] = strb[j-1];
            lengtha++;
            m2 = d[i][j-1]+1;
            for(k = i-1; k < lengtha; k++) a[k] = a[k+1];
            lengtha--;
            m3 = d[i-1][j]+1;
            r = m1;
            if( m2 < r) r = m2;
            if(m3 < r) r = m3;
            d[i][j] = r;
            lengtha = laa;
            for(l = 0; l <= lengtha; l++) a[l] = stra[l];
        }
    }
    
    r = d[lengtha][lengthb];
    free(a);
    for(i = 0; i < lengthmin+2; i++) free(d[i]);
    free(d);
    return(r);
}


//------------------------------------------------------------
void particleWord::setup(){
    
    //ttfword.loadFont("Lekton-Regular.ttf", 100);
    
}
//------------------------------------------------------------
void particleWord::draw(){
    
    
    ofSetColor(255,0,0);
    ofRectangle boundingBox = ttfword->getStringBoundingBox(word, 0, 0);
    ofPoint midPt;
    midPt.set( boundingBox.x + boundingBox.width / 2.0, boundingBox.y + boundingBox.height / 2.0);
    
    ofSetColor(color);
    color.a = ofMap(cos(ofGetElapsedTimef()), -1, 1, 40, 255);
    float newSize = ofMap(size, 0, ofGetElapsedTimef(), 0.1, 2.0);
    
    ofPushMatrix(); {
        ofTranslate(pos.x, pos.y);
        ofScale(newSize, newSize);
        ttfword->drawString(word, -midPt.x, -midPt.y);
        //ofRect(-midPt.x, midPt.y, boundingBox.width, boundingBox.height);
    } ofPopMatrix();
    
    //    ofRectangle scaledRect;
    //    scaledRect.width = boundingBox.width * newSize;
    //    scaledRect.height = boundingBox.height * newSize;
    //    ofRect(0,0, scaledRect.width, scaledRect.height);
    
    textBound.set(pos.x, pos.y, boundingBox.width * newSize, boundingBox.height * newSize);
    
    
}


//------------------------------------------------------------
particleWord::particleWord(){

    setInitialCondition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, 0);
    damping = 0.02f;
    //    color.r = ofRandom(255);
    //    color.g = ofRandom(255);
    //    color.b = ofRandom(255);
    
    color.r = 0;
    color.g = 0;
    color.b = 0;
    
    
    
}

//------------------------------------------------------------
void particleWord::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particleWord::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particleWord::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}


//------------------------------------------------------------
void particleWord::addRepulsionForce(particleWord &p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is:
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length
    
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
        p.frc.x = p.frc.x - diff.x * scale * pct;
        p.frc.y = p.frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particleWord::addRepulsionForce(float x, float y, float radius, float scale){
    
    // ----------- (1) make a vector of where this position is:
    
    ofVec2f posOfForce;
    posOfForce.set(x,y);
    
    // ----------- (2) calculate the difference & length
    
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
    }
}


//------------------------------------------------------------
void particleWord::addAttractionForce(float x, float y, float radius, float scale){
    
    // ----------- (1) make a vector of where this position is:
    
    ofVec2f posOfForce;
    posOfForce.set(x,y);
    
    // ----------- (2) calculate the difference & length
    
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particleWord::addAttractionForce(particleWord & p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is:
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length
    
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
        p.frc.x = p.frc.x + diff.x * scale * pct;
        p.frc.y = p.frc.y + diff.y * scale * pct;
    }
    
}


//------------------------------------------------------------
void particleWord::addClockwiseForce(particleWord &p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is:
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length
    
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x - diff.y * scale * pct;
        frc.y = frc.y + diff.x * scale * pct;
        p.frc.x = p.frc.x + diff.y * scale * pct;
        p.frc.y = p.frc.y - diff.x * scale * pct;
    }
}


//------------------------------------------------------------
void particleWord::addCounterClockwiseForce(particleWord &p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is:
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length
    
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x + diff.y * scale * pct;
        frc.y = frc.y - diff.x * scale * pct;
        p.frc.x = p.frc.x - diff.y * scale * pct;
        p.frc.y = p.frc.y + diff.x * scale * pct;
        
    }
}

//------------------------------------------------------------
float particleWord::getLevDistScale(particleWord &p){
    
    string wordString;
    wordString = p.word;
    int length = levenshtein(wordString, word);
    if (length >= 15){
        length = 15;
    }
    //return ofMap(length/1.0f, 0, 20, 0.01f, 0.09f);
    return 0.08f/length;
}


//------------------------------------------------------------
void particleWord::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

//------------------------------------------------------------
void particleWord::update(){
    vel = vel + frc;
    pos = pos + vel;
}

//------------------------------------------------------------
void particleWord::bounceOffWalls(){
    
    // sometimes it makes sense to damped, when we hit
    bool bDampedOnCollision = true;
    bool bDidICollide = false;
    
    // what are the walls
    float minx = textBound.width / 2;
    float miny = textBound.height / 2;
    float maxx = ofGetWidth() - textBound.width / 2;
    float maxy = ofGetHeight() - textBound.height / 2;
    
    if (pos.x > maxx){
        pos.x = maxx; // move to the edge, (important!)
        vel.x *= -1;
        bDidICollide = true;
    } else if (pos.x < minx){
        pos.x = minx; // move to the edge, (important!)
        vel.x *= -1;
        bDidICollide = true;
    }
    
    if (pos.y > maxy){
        pos.y = maxy; // move to the edge, (important!)
        vel.y *= -1;
        bDidICollide = true;
    } else if (pos.y < miny){
        pos.y = miny; // move to the edge, (important!)
        vel.y *= -1;
        bDidICollide = true;
    }
    
    if (bDidICollide == true && bDampedOnCollision == true){
        vel *= 0.3;
    }
    
}


