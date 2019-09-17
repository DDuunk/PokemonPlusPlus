#pragma once

#include "Graphics.h"

class GameManager {

private:

	static GameManager* sInstance;

	bool mQuit;
	Graphics* mGrapics;

	SDL_Event mEvents;

public:

	static GameManager* Instance();
	static void Release();

	void Run();

private:

	GameManager();
	~GameManager();
};