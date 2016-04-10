/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

#include "..\..\depend\glm\vec2.hpp"
#include "..\_colours.h"
#include "..\basic\Box.h"
#include "..\_macro.h"


class Game
{
private:
	glm::ivec2 _current_direction;
	bool _ready;
	Box *_board_init;
	Box *_snake_init;

	void _Init();
	void _InitBoard();
	void _InitStart();

public:
	Game();
	~Game();

	void Restart();
	void UpdateDirection(glm::ivec2 direction);
	int UpdatePosition();
	void GenerateFruit();
	void Draw();
	void Init();
};