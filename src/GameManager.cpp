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

	mAssetMgr = AssetManager::Instance();

	mTimer = Timer::Instance();

	mTex = new Texture("IntroSpriteSheet.png");
}

GameManager::~GameManager() {
	Graphics::Release();
	mGrapics = NULL;

	AssetManager::Release();
	mAssetMgr = NULL;

	Timer::Release();
	mTimer = NULL;

	delete mTex;
	mTex = NULL;
}

void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();

		while (SDL_PollEvent(&mEvents) != 0) {
			if (mEvents.type == SDL_QUIT)
				mQuit = true;
		}

		if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {
//			printf("DeltaTime: %F\n", mTimer->DeltaTime());

			mGrapics->ClearBackBuffer();
	
			mTex->Render();

			mGrapics->Render();

			mTimer->Reset();
		}
	}
}