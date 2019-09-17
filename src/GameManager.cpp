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

	mTimer = Timer::Instance();

	mParent = new GameEntity(100.0f, 400.0f);
	mChild = new GameEntity(100.0f, 500.0f);

	printf("Child local pos: (%F, %F)\n", mChild->Pos(GameEntity::world).x, mChild->Pos(GameEntity::world).y);

	mChild->Parent(mParent);

	printf("Child local pos: (%F, %F)\n", mChild->Pos(GameEntity::world).x, mChild->Pos(GameEntity::world).y);
}

GameManager::~GameManager() {
	Graphics::Release();
	mGrapics = NULL;

	Timer::Release();
	mTimer = NULL;

	delete mParent;
	delete mChild;
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

			mParent->Rotation(mParent->Rotation(GameEntity::local) + 0.1f);
			printf("Parent rotation: %F\n", mParent->Rotation(GameEntity::local));
			printf("Child local pos: (%F, %F)\n", mChild->Pos(GameEntity::world).x, mChild->Pos(GameEntity::world).y);

			mGrapics->Render();

			mTimer->Reset();
		}
	}
}