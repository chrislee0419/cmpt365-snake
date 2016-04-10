/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include <map>

#include "..\..\depend\glew\glew.h"
#include "..\..\depend\freeglut\freeglut.h"
#include "..\..\depend\freetype\ft2build.h"
#include FT_FREETYPE_H

#include "..\..\shaders\Shader.h"
#include "..\..\depend\glm\vec2.hpp"
#include "..\..\depend\glm\vec4.hpp"

#define ROBOTO 0
#define UBUNTU 1

struct Character
{
	GLuint TextureID;
	glm::ivec2 Size;
	glm::ivec2 Bearing;
	GLuint Advance;
};

class Text
{
private:
	static Shader _shader;
	static std::map<char, Character> _ubuntu;
	static std::map<char, Character> _roboto;
	GLuint _vao;
	GLuint _vbo;
	char _text[200];
	glm::vec4 _colour;
	int _xpos;
	int _ypos;
	float _size;
	int _font;
	bool _ready;

	void _Init(int font, float size, std::string text, int xpos, int ypos, glm::vec4 colour);
	bool _Assert();
	void _CreateGLObjects();

public:
	Text();
	Text(std::string text, int xpos, int ypos);
	Text(int font, float size, std::string text, int xpos, int ypos);
	Text(std::string text, int xpos, int ypos, glm::vec4 colour);
	Text(int font, float size, std::string text, int xpos, int ypos, glm::vec4 colour);
	Text(const Text &copytext);
	~Text();

	float GetHeight();
	float GetWidth();

	void SetFont(int font);
	void SetSize(float size);
	void SetText(std::string text);
	void SetColour(glm::vec4 colour);
	void SetXPosition(int xpos);
	void SetYPosition(int ypos);
	void SetPosition(int xpos, int ypos);
	static void SetShader(const Shader shader);
	static void PrepareFT();

	void Draw(int x_translate, int y_translate);

};
