#version 330

in vec4 vertex;
out vec2 TexCoor;

uniform int xsize;
uniform int ysize;

void main(void) {

	mat4 scale = mat4(
		2.0/xsize,	0.0,		0.0,	0.0,
		0.0,		2.0/ysize,	0.0, 	0.0,
		0.0,		0.0,		1.0,	0.0,
		0.0,		0.0,		0.0,	1.0
	);

	vec4 position = vec4(vertex.xy, 0, 1) + vec4(-400, -400, 0, 0);
	gl_Position = scale * position;

	TexCoor = vertex.zw;
}