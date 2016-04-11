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
	_textcount = 14;
	_boxcount = 4;

	_background = new Box(700, 600, 0, 0, 10, DARKGREY, LIGHTGREY);

	_boxes = (Box*)malloc(sizeof(Box)*_boxcount);
	_boxes[0] = Box(40, 40, 40, 145, 5, DARKGREY, LIGHTGREY);
	_boxes[1] = Box(40, 40, 40, 195, 5, GOLD, YELLOW);
	_boxes[2] = Box(40, 40, 40, 245, 5, RED, PINK);
	_boxes[3] = Box(40, 40, 40, 295, 5, DARKGREEN, LIGHTGREEN);

	_text = (Text*)malloc(sizeof(Text)*_textcount);
	_text[0] = Text(UBUNTU, 1.6f, "Fruit pellet - eat this to grow and gain points.", 100, 305, BLACK);
	_text[1] = Text(UBUNTU, 1.6f, "Snake head - this is what you control.", 100, 255, BLACK);
	_text[2] = Text(UBUNTU, 1.6f, "Snake body - don't eat yourself!", 100, 205, BLACK);
	_text[3] = Text(UBUNTU, 1.6f, "Wall - don't bump into walls! (appears after a score of 5)", 100, 155, BLACK);
	_text[4] = Text(ROBOTO, 2.2f, "---  HELP  ---", 250, 550, BLACK);
	_text[5] = Text(ROBOTO, 1.8f, "- CONTROLS -", 35, 525, BLACK);
	_text[6] = Text(UBUNTU, 1.4f, "\"p\"\t          -   pauses and unpauses the game", 40, 500, BLACK);
	_text[7] = Text(UBUNTU, 1.4f, "\"i\"\t          -   displays the instructions/help menu", 40, 475, BLACK);
	_text[8] = Text(UBUNTU, 1.4f, "\"r\"\t          -   resets the game", 40, 450, BLACK);
	_text[9] = Text(UBUNTU, 1.4f, "\"q\"\t          -   exits the game", 40, 425, BLACK);
	_text[10] = Text(UBUNTU, 1.4f, "\"(arrow key)\"  -   moves the player character (snake)", 40, 400, BLACK);
	_text[11] = Text(ROBOTO, 1.8f, "- BLOCK TYPES -", 35, 350, BLACK);
	_text[12] = Text(ROBOTO, 2.2f, "PRESS \"I\" TO EXIT THIS MENU", 0, 40, RED);
	_text[13] = Text(UBUNTU, 1.2f, "(\"Snake\" is created by Chris Lee and Matthew Tseng for our CMPT 365 Term Project)", 35, 100, RED);

	// center header text
	int width = (int)_text[4].GetWidth();
	_text[4].SetXPosition((700 - width)/2);

	// center exit text
	width = (int)_text[12].GetWidth();
	_text[12].SetXPosition((700 - width)/2);
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
