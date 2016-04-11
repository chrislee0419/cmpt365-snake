/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "..\basic\Box.h"
#include "..\basic\Text.h"

class InstructionsMenu
{
private:
	int _textcount, _boxcount;
	Box *_background;
	Box *_boxes;
	Text *_text;

public:
	InstructionsMenu();
	~InstructionsMenu();

	void Draw(int x_translate, int y_translate);

};
