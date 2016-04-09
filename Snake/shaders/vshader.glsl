#version 330

in vec4 vPosition;
in vec4 vColour;
out vec4 colour;

uniform int xsize;
uniform int ysize;

void main(void) {

	mat4 scale = mat4(
		2.0/xsize,	0.0,		0.0,	0.0,
		0.0,		2.0/ysize,	0.0, 	0.0,
		0.0,		0.0,		1.0,	0.0,
		0.0,		0.0,		0.0,	1.0
	);

	vec4 position = vPosition + vec4(-400, -400, 0, 0);
	gl_Position = scale * position;

	colour = vColour;
}