#include "Graphics.h"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = NULL;

Graphics* Graphics::Instance() {
	if (sInstance == NULL) 
		sInstance = new Graphics();
	
	return sInstance;
}

void Graphics::Release() {
	delete sInstance;
	sInstance = NULL;

	sInitialized = false;
}

bool Graphics::Initialized() {
	return sInitialized;
}

Graphics::Graphics() {
	mBackBuffer = NULL;

	sInitialized = Init();
}

Graphics::~Graphics() {
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	SDL_Quit();
}

bool Graphics::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Initilization Error: %s\n", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow("Pokemon++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (mWindow == NULL) {
		printf("Window Creation Error: %s\n", SDL_GetError());
		return false;
	}

	mBackBuffer = SDL_GetWindowSurface(mWindow);

	return true;
}

void Graphics::Render() {
	SDL_UpdateWindowSurface(mWindow);
}