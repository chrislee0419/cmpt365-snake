/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include <iostream>
#include <stdexcept>

#include "..\..\depend\glew\glew.h"
#include "..\..\depend\freeglut\freeglut.h"
#include "..\..\shaders\Shader.h"
#include "..\..\depend\glm\vec4.hpp"
#include "..\_colours.h"

class Game
{
private:
	bool _ready;

	void _Init();
	void _InitBoard();
	void _InitStart();
	bool _ready;

public:
	Game();
	~Game();

	void Restart();
	void Move(glm::vec2 direction);
	void Init();
};