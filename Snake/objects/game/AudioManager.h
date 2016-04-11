/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include"..\..\depend\SFML\SFML\Audio.hpp"

class AudioManager
{
private:
	sf::SoundBuffer _action, _eat, _lose, _move1, _move2;
	sf::Music _game_music, _pause_music;
	bool _move_state;

public:
	AudioManager();
	~AudioManager();

	void ResetMoveSound();
	void PlaySound(int sound_code);
	void PlayMusic(int music_code);
	void StopMusic();
};