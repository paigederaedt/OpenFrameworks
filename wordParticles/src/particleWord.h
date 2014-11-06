#include "ofMain.h"

class particleWord {
    
public:
    
    ofVec2f pos;
    ofTrueTypeFont ttfword;
    string word;
    bool bFirst;
    
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
    
    void addRepulsionForce( float px, float py, float radius, float strength);
    void addAttractionForce( float px, float py, float radius, float strength);
    void addClockwiseForce( float px, float py, float radius, float strength);
    void addCounterClockwiseForce( float px, float py, float radius, float strength);
    
    float damping;
    
};