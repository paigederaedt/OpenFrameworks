#version 120

uniform float mousex;
uniform float mousey;
uniform float time;

void main(void)
{
	float width = 1024.0;
	float height = 768.0;
	float x = gl_FragCoord.x / width;
	float y = gl_FragCoord.y / height;

	float mx = mousex / width;
	float my = mousey / height;

	float red, green, blue;

	if (tan(x * 50) > sin(y * 80.0)) {
		red = sin(sin(mx * time * 50.0));
		blue = cos(tan(x * y) / time);
		green = sin(tan(x * time) * my);
	} 
	else {
		red = tan(tan(y + time) * 20.2);
		blue = cos(sin(time * my) / y + 1);
		green = sin(tan(x + time));
	}

	gl_FragColor = vec4(red, green, blue, 1.0);
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}