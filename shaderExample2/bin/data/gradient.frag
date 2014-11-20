//
varying vec4 position;
//
uniform float mousex;
uniform float mousey;

//uniform float color;

void main() {
	
	vec2 pixelpos = vec2(position.x, position.y);
    vec2 mousepos = vec2(mousex, mousey);
    
	float dist = distance(pixelpos, mousepos);
	float val = 0.0;
	if (dist < 300.0){
		val = 1.0 -  dist/300.0;
	}
	gl_FragColor = vec4 (val, val, val, 1.0);
	
}
