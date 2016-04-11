/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include <queue>
#include <deque>
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
	glm::ivec2 _prev_direction;
	std::queue<glm::ivec2, std::deque<glm::ivec2>> _snake;
	int _board[39][29];		// board[x][y] represents whether the cell (x, y) is occupied
	int _numwalls;
	int _fruitsate;
	glm::ivec2 _head;
	Box *_board_box;
	Box *_background;
	bool _grow;

	void _InitBoard();
	void _InitStart();
	void _GenerateFruit();
	void _GenerateWall();
	void _UpdateSnake(glm::ivec2 new_head, bool grow);

public:
	Game();
	~Game();

	void Restart();
	bool UpdateDirection(glm::ivec2 direction);
	int UpdatePosition();
	void Draw();
};