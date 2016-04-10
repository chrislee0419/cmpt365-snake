/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "..\depend\glew\glew.h"
#include "..\depend\freeglut\freeglut.h"
#include "..\depend\glm\vec4.hpp"

#include "..\objects\basic\Box.h"
#include "..\objects\basic\Text.h"

#include "..\shaders\Shader.h"
#include "..\objects\_colours.h"

class Test
{
private:
	static Shader _shader;
	GLuint _vao;
	GLuint _pos_vbo, _col_vbo;
	
	Box *box_objects;
	void _CreateBoxTest();
	void _DisplayBoxTest();
	bool _box_test;

	Text *text_objects;
	void _CreateTextTest();
	void _DisplayTextTest();
	bool _text_test;

	//Sprite *sprite_objects;
	//void _CreateSpriteTest();
	//void _DispalySpriteTest();

public:
	Test();
	~Test();

	void SetupTest();
	void DisplayTest();
	static void SetProgram(const Shader shader);

	void BasicTest();
	void BasicTestDisplay();
};