/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include "InstructionsMenu.h"
#include "..\_colours.h"

// Constructor
InstructionsMenu::InstructionsMenu()
{
	// number of objects
	_textcount = 11;
	_boxcount = 3;

	_background = new Box(700, 600, 0, 0, 10, DARKGREY, LIGHTGREY);

	_boxes = (Box*)malloc(sizeof(Box)*_boxcount);
	_boxes[0] = Box(40, 40, 40, 35, 5, GOLD, YELLOW);
	_boxes[1] = Box(40, 40, 40, 85, 5, RED, PINK);
	_boxes[2] = Box(40, 40, 40, 135, 5, DARKGREEN, LIGHTGREEN);

	_text = (Text*)malloc(sizeof(Text)*_textcount);
	_text[0] = Text(UBUNTU, 1.6f, "Snake body - don't touch this or the game is over!", 100, 45, BLACK);
	_text[1] = Text(UBUNTU, 1.6f, "Snake head - this is what you control.", 100, 95, BLACK);
	_text[2] = Text(UBUNTU, 1.6f, "Food pellet - eat this to gain points.", 100, 145, BLACK);
	_text[3] = Text(ROBOTO, 2.2f, "---  HELP  ---", 250, 550, BLACK);
	_text[4] = Text(ROBOTO, 1.8f, "- CONTROLS -", 35, 525, BLACK);
	_text[5] = Text(UBUNTU, 1.4f, "\"p\"\t          -   pauses and unpauses the game", 40, 500, BLACK);
	_text[6] = Text(UBUNTU, 1.4f, "\"i\"\t          -   displays the instructions/help menu", 40, 475, BLACK);
	_text[7] = Text(UBUNTU, 1.4f, "\"r\"\t          -   resets the game", 40, 450, BLACK);
	_text[8] = Text(UBUNTU, 1.4f, "\"q\"\t          -   exits the game", 40, 425, BLACK);
	_text[9] = Text(UBUNTU, 1.4f, "\"(arrow key)\"  -   moves the player character (snake)", 40, 400, BLACK);
	_text[10] = Text(ROBOTO, 1.8f, "- BLOCK TYPES -", 35, 245, BLACK);

	// center header text
	int width = (int)_text[3].GetWidth();
	_text[3].SetXPosition((700 - width)/2);
}

// Destructor
InstructionsMenu::~InstructionsMenu()
{
	delete _background;
	free(_boxes);
	free(_text);
}

// Rendering method
void InstructionsMenu::Draw(int x_translate, int y_translate)
{
	_background->Draw(x_translate, y_translate);

	for (int i = 0; i < _boxcount; i++)
		_boxes[i].Draw(x_translate, y_translate);

	for (int i = 0; i < _textcount; i++)
		_text[i].Draw(x_translate, y_translate);
}
