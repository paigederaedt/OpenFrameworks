#include "ofMain.h"

class word {
    
public:
    
    string text;
    ofPoint pos;
    ofTrueTypeFont ttfword;
    float size;
    ofColor color;
    ofRectangle textBound;
    
    void draw();
    void setup();
    word();
    virtual ~word(){};
    
    
};

