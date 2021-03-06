/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include <iostream>

#include "AudioManager.h"
#include "..\_macro.h"

// Constructor
AudioManager::AudioManager()
{
	// prepare audio files
	if (!_action.loadFromFile("audio/action.wav"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"action.wav\".");
	if (!_eat.loadFromFile("audio/eat.wav"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"eat.wav\".");
	if (!_lose.loadFromFile("audio/lose.wav"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"lose.wav\".");
	if (!_move1.loadFromFile("audio/move1.wav"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"move1.wav\".");
	if (!_move2.loadFromFile("audio/move2.wav"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"move2.wav\".");

	// prepare music
	if (!_game_music.openFromFile("audio/game_music.ogg"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"game_music.ogg\".");
	if (!_pause_music.openFromFile("audio/pause_music.ogg"))
		throw std::runtime_error("Audio [ERROR]: Could not open \"pause_music.ogg\".");

	_sound;
	_game_music.setVolume(100);
	_pause_music.setVolume(100);

	_pitch = 1.0f;
	_move_state = true;
}

// Destructor
AudioManager::~AudioManager() {}

// Public methods
void AudioManager::ResetMoveSound()
{
	_move_state = true;
}

void AudioManager::PlaySound(int sound_code)
{
	switch (sound_code)
	{
	case SOUND_ACTION:
		_sound.setBuffer(_action);
		_sound.setVolume(60);
		break;
	case SOUND_MOVE:
		if (_move_state)
			_sound.setBuffer(_move1);
		else
			_sound.setBuffer(_move2);
		_sound.setVolume(20);
		_move_state = !_move_state;
		break;
	case SOUND_EAT:
		_sound.setBuffer(_eat);
		_sound.setVolume(80);
		break;
	case SOUND_LOSE:
		_sound.setBuffer(_lose);
		_sound.setVolume(100);
		break;
	default:
		return;
	}
	
	_sound.play();
}

void AudioManager::PlayMusic(int music_code)
{
	_game_music.pause();
	_pause_music.pause();

	if (music_code == MUSIC_PLAY)
	{
		_game_music.setPitch(_pitch);
		_game_music.play();
		_game_music.setLoop(true);
	}
	else if (music_code == MUSIC_PAUSE)
	{
		_pause_music.play();
		_pause_music.setLoop(true);
	}
}

void AudioManager::StopMusic()
{
	_game_music.stop();
	_pause_music.stop();
}

void AudioManager::IncreasePitch()
{
	if (_pitch < 2.0f)
	{
		_pitch += 1.0f / 200.0f;
		_game_music.setPitch(_pitch);
	}
}

void AudioManager::ResetPitch()
{
	_game_music.setPitch(_pitch = 1.0f);
}
