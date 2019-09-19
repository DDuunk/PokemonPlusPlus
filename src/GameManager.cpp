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

	mInputMgr = InputManager::Instance();

	mTimer = Timer::Instance();

	mTex = new Texture("Hero&Heroine_Spritesheet.png", 8, 37, 15, 19);
	mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

GameManager::~GameManager() {
	Graphics::Release();
	mGrapics = NULL;

	AssetManager::Release();
	mAssetMgr = NULL;

	InputManager::Release();
	mInputMgr = NULL;

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

			mInputMgr->Update();

			if (mInputMgr->KeyDown(SDL_SCANCODE_W)) {
				mTex->Translate(Vector2(0.0f, -40.0f) * mTimer->DeltaTime());
			} else if (mInputMgr->KeyDown(SDL_SCANCODE_S)) {
				mTex->Translate(Vector2(0.0f, 40.0f) * mTimer->DeltaTime());
			}

			mGrapics->ClearBackBuffer();
	
			mTex->Render();

			mGrapics->Render();

			mTimer->Reset();
		}
	}
}