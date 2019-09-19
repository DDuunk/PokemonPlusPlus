#pragma once

#include "Texture.h"
#include "Timer.h"
#include "InputManager.h"

class GameManager {

private:
	static GameManager* sInstance;

	const int FRAME_RATE = 120;

	bool mQuit;
	Graphics* mGrapics;
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;

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