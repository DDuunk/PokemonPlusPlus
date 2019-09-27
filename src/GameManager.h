/**
 * @file		GameManager.cpp
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Game manager
 */
#pragma once

#include "AnimatedTexture.h"
// #include "Timer.h"
#include "InputManager.h"
#include "AudioManager.h"

class GameManager {

private:
	static GameManager* sInstance;

	const int FRAME_RATE = 120;

	bool mQuit;
	Graphics* mGrapics;
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;
	AudioManager* mAudioMgr;

	Timer* mTimer;

	SDL_Event mEvents;

	Texture* mTex;

public:
	static GameManager* Instance();
	static void Release();

	void Run();

private:
	GameManager();
	~GameManager();
};