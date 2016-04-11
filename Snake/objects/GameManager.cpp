/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include "GameManager.h"
#include "_macro.h"

using glm::ivec2;

// Constructor
GameManager::GameManager()
{
	_top_menu = new Menu();
	_game = new Game();
	_audio = new AudioManager();
	_instruct = new InstructionsMenu();

	_game_state = STATE_INSTRUCT;
	_prev_game_state = STATE_PLAY;
	_game_speed = DEFAULT_SPEED;
}

// Destructor
GameManager::~GameManager()
{
	delete _top_menu;
	delete _game;
	delete _audio;
	delete _instruct;
}

// Input methods

// called on key: "i"
// when in another state - changes to INSTRUCT state
// when in INSTRUCT state - changes to prev state
int GameManager::Instructions()
{
	_audio->PlaySound(SOUND_ACTION);

	// already in INSTRUCT STATE
	if (_game_state == STATE_INSTRUCT)
	{
		_game_state = _prev_game_state;
		if (_game_state == STATE_PLAY)
			_audio->PlayMusic(MUSIC_PLAY);
		else
			_audio->PlayMusic(MUSIC_PAUSE);
		return _game_speed;
	}
	// not in INSTRUCT STATE
	else
	{
		_audio->PlayMusic(MUSIC_PAUSE);
		_prev_game_state = _game_state;
		_game_state = STATE_INSTRUCT;
		return 0;
	}
}

// called on key: "p"
// used to pause and unpause the game
// restarts game when in GAMEOVER state
// continues game when in INSTRUCT state
int GameManager::Pause()
{
	if (_game_state == STATE_PLAY)
	{
		_audio->PlaySound(SOUND_ACTION);
		_audio->PlayMusic(MUSIC_PAUSE);
		_game_state = STATE_PAUSED;
		return 0;
	}
	else if (_game_state == STATE_PAUSED)
	{
		_audio->PlaySound(SOUND_ACTION);
		_audio->PlayMusic(MUSIC_PLAY);
		_game_state = STATE_PLAY;
		return _game_speed;
	}
	else if (_game_state == STATE_GAMEOVER)
	{
		return Reset();
	}
	else if (_game_state == STATE_INSTRUCT)
	{
		return Instructions();
	}

	return 0;
}

int GameManager::Reset()
{
	_audio->PlaySound(SOUND_ACTION);
	_RestartGame();
	_game->Restart();
	return _game_speed;
}

void GameManager::PlayerDirection(int direction)
{
	if (_game_state != STATE_PLAY)
		return;

	bool sound = false;
	switch (direction)
	{
	case MOVE_UP:
		sound = _game->UpdateDirection(ivec2(0, 1));
		break;
	case MOVE_DOWN:
		sound = _game->UpdateDirection(ivec2(0, -1));
		break;
	case MOVE_LEFT:
		sound = _game->UpdateDirection(ivec2(-1, 0));
		break;
	case MOVE_RIGHT:
		sound = _game->UpdateDirection(ivec2(1, 0));
	}

	if (sound)
		_audio->PlaySound(SOUND_ACTION);
}

// Timer method
int GameManager::Timer()
{
	if (_game_state == STATE_PLAY)
	{
		int val = _game->UpdatePosition();

		if (val == MOVE_OK)
		{
			_audio->PlaySound(SOUND_MOVE);
			return _game_speed;
		}
		else if (val == MOVE_GROW)
		{
			if (_game_speed > MAX_SPEED)
				_game_speed -= 10;
			_audio->PlaySound(SOUND_EAT);
			_top_menu->IncrementScore();
			return _game_speed;
		}
		else if (val == MOVE_HIT)
		{
			_audio->PlaySound(SOUND_LOSE);
			_audio->PlayMusic(MUSIC_PAUSE);
			_game_state = STATE_GAMEOVER;

			return 0;
		}
	}
	return 0;
}

// Rendering method
void GameManager::Draw()
{
	_top_menu->Draw();
	_game->Draw();

	if (_game_state == STATE_INSTRUCT)
		_instruct->Draw(50, 100);
}

// Helper methods

void GameManager::_RestartGame()
{
	_game_speed = DEFAULT_SPEED;
	_top_menu->ResetScore();
	_audio->ResetMoveSound();
	_audio->PlayMusic(MUSIC_PLAY);
	_prev_game_state = STATE_PLAY;
	_game_state = STATE_PLAY;
}