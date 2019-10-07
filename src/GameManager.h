/**
 * @file		GameManager.cpp
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Used to intialize and release all other manager
 *				Contains the game loop as well as the Update and Render functions
 *				Used to make sure all functions are called in the correct order
 */
#pragma once

#include "AnimatedTexture.h"
#include "Timer.h"
#include "InputManager.h"
#include "AudioManager.h"

class GameManager {

private:
	// Needed to make GameManager a singleton class
	static GameManager* sInstance;

	// The target frame rate of the game
	const int FRAME_RATE = 120;

	// Used to exit the game loop
	bool mQuit;

	// List of Managers to be initialized and released
	Graphics* mGrapics;
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;
	AudioManager* mAudioMgr;

	// Used to limit the frame rate
	Timer* mTimer;

	// Used to catch the event when the user exits the game
	SDL_Event mEvents;

	Texture* mTex;

public:
	/**
	 * @brief		Returns a pointer to the class instance
	 */
	static GameManager* Instance();
	/**
	 * @brief		Releases the class instance and sets it back to NULL
	 *				Is called when the game is closed
	 *				Releases all other managers
	 */
	static void Release();

	/**
	 * @brief 		Contains the game loop, is called once in the main function
	 */
	void Run();

private:
	/**
	 * @brief		Contructor is private so that Instance() must be used to get an instance when needed
	 */
	GameManager();
	/**
	 * @brief		Destructor is private so that the instance can only be destroyed using Release()
	 */
	~GameManager();

	/**
	 * @brief		Is called before Update, and is used for things that need to be updated first
	 *				for example: updating input state
	 */
	void EarlyUpdate();

	/**
	 * @brief		Used to update entities, all transformations are to be done in this functions
	 */
	void Update();

	/**
	 * @brief		Is called after Update and is used for things that need to be updated last
	 *				for example: collision detection or resetting the timer
	 */
	void LateUpdate();

	/**
	 * @brief		Clears the back buffer, and then is used to render all game entities
	 *				Is called after Late Update
	 */
	void Render();
};