#ifndef CREATURE_H
#define CREATURE_H

#include "ofMain.h"

class creature {
    
public:
    
    creature();
    
    void	draw();
    void	xenoToPoint(float catchX, float catchY);
    
    ofPoint		pos;
    ofPoint		prevPos;
    
    float		angle;
    
    
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
    
    float   radius;
    float   radiusMult;
    ofPoint transPos;
    int     colorR;
    int     colorG;
    int     colorB;
    float   noiseFactor;
    ofPoint trailPos;
    float lenVel;
    
    
    
    
};

#endif // CREATURE_H
