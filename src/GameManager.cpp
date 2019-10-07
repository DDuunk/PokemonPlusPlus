#include "GameManager.h"

// Initializing to NULL
GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {
	// Create a new instance if no instance was created before
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

	// Initialize SDL
	mGrapics = Graphics::Instance();

	// Quits the game if SDL fails to initialize
	if (!Graphics::Initialized())
		mQuit = true;

	// Initialize AssetManager
	mAssetMgr = AssetManager::Instance();
	// Initialize InputManager
	mInputMgr = InputManager::Instance();
	// Initialize AudioManager
	mAudioMgr = AudioManager::Instance();
	// Initialize Timer
	mTimer = Timer::Instance();

	// Initialize any other objects here
	mTex = new Texture("Hello World!", "ARCADE_I.TTF", 36, { 255, 0, 0 });
	mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

GameManager::~GameManager() {
	AudioManager::Release();
	mAudioMgr = NULL;

	AssetManager::Release();
	mAssetMgr = NULL;

	Graphics::Release();
	mGrapics = NULL;

	InputManager::Release();
	mInputMgr = NULL;

	Timer::Release();
	mTimer = NULL;

	delete mTex;
	mTex = NULL;
}

void GameManager::EarlyUpdate() {
	//	Updating the input state before any other updates are run to make sure the Input check is accurate
	mInputMgr->Update();
}

void GameManager::Update() {
	//	GameEntity Updates should happen here

	if (mInputMgr->KeyDown(SDL_SCANCODE_1)) {
		mAudioMgr->PlaySFX("01-coin-credit.wav");
	}

	mTex->Rotate(10 * mTimer->DeltaTime());
}

void GameManager::LateUpdate() {
	// Any collision detection should happen here

	mInputMgr->UpdatePrevInput();
	mTimer->Reset();
}

void GameManager::Render() {
	// Clears the last frame's render from the back buffer
	mGrapics->ClearBackBuffer();

	// All other rendering is to happen here
	mTex->Render();

	// Renders the current frame
	mGrapics->Render();
}

void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();

		while (SDL_PollEvent(&mEvents) != 0) {
			// Checks if the user quit the game
			if (mEvents.type == SDL_QUIT)
				mQuit = true;
		}

		// Limits the frame rate to FRAME_RATE
		if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {
			EarlyUpdate();
			Update();
			LateUpdate();
			Render();
		}
	}
}