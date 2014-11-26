#include "ofMain.h"

class particleWord {
    
public:
    
    ofVec2f pos;
    ofTrueTypeFont * ttfword;
    string word;
    float size;
    ofColor color;
    
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    void draw();
    void setup();
    
    particleWord();
    virtual ~particleWord(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addAttractionForce(float x, float y, float radius, float scale);
    
    void addRepulsionForce(particleWord &p, float radius, float scale);
    void addAttractionForce(particleWord &p, float radius, float scale);
    void addClockwiseForce(particleWord &p, float radius, float scale);
    void addCounterClockwiseForce(particleWord &p, float radius, float scale);
    
    float getLevDistScale(particleWord &p);
    void bounceOffWalls();
    
    
    float damping;
    
    ofRectangle textBound;
};