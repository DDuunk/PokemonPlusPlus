/**
 * @file		AudioManager.cpp
 * @date		27-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Audio handler
 */
#pragma once

#include "AssetManager.h"

class AudioManager {
	
private:
	static AudioManager* sInstance;

	AssetManager* mAssetMgr;

public:
	static AudioManager* Instance();
	static void Release();

	void PlayMusic(std::string filename, int loops = -1);
	void PauseMusic();
	void ResumeMusic();

	void PlaySFX(std::string filename, int loops = 0, int channel = 0);

private:
	AudioManager();
	~AudioManager();


};