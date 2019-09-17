#include "GameManager.h"

GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {
	if (sInstance == NULL)
		sInstance = new GameManager();
	
	return sInstance;
}

void GameManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

GameManager::GameManager() {
	mQuit = false;

	mGrapics = Graphics::Instance();

	if (!Graphics::Initialized())
		mQuit = true;
}

GameManager::~GameManager() {
	Graphics::Release();
	mGrapics = NULL;
}

void GameManager::Run() {
	while (!mQuit) {
		while (SDL_PollEvent(&mEvents) != 0) {
			if (mEvents.type == SDL_QUIT)
				mQuit = true;

			mGrapics->Render();
		}
	}
}