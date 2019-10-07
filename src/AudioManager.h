/**
 * @file		AudioManager.cpp
 * @date		27-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Plays WAV files
 *				Can play one BGM at a time, and many sound effects at once
 */
#pragma once

#include "AssetManager.h"

class AudioManager {

private:
	// Needed to make AudioManager a singleton class
	static AudioManager* sInstance;

	// Used to load audio files
	AssetManager* mAssetMgr;

public:
	/**
	 * @brief		Returns a pointer to the class instance
	 */
	static AudioManager* Instance();
	/**
	 * @brief		Releases the class instance and sets it back to NULL
	 */
	static void Release();

	/**
	 * @brief		Sets the BGM to play using the provided file,
	 *
	 * @param loops loop = -1 is infinite looping (default: -1)
	 */
	void PlayMusic(std::string filename, int loops = -1);
	/**
	 * @brief		Pauses the currently playing BGM if there is any
	 */
	void PauseMusic();
	/**
	 * @brief		Resumes paused BGM
	 */
	void ResumeMusic();
	/**
	 * @brief		Plays a sound effect from the file provided
	 * 				plays if for the given loops on the given channel
	 *
	 * @param loops default: 0
	 * @param channel default: 0
	 */
	void PlaySFX(std::string filename, int loops = 0, int channel = 0);

private:
	/**
	 * @brief		Contructor is private so that Instance() must be used to get an instance when needed
	 */
	AudioManager();
	/**
	 * @brief		Destructor is private so that the instance can only be destroyed using Release()
	 */
	~AudioManager();
};