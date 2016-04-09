#version 330

in vec2 TexCoor;
out vec4 fColour;

uniform sampler2D text;
uniform vec4 textColour;

void main(void) {
	vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoor).r);
	fColour = textColour * sampled;
}