/**
 * @file		InputManager.cpp
 * @date		19-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Input handler
 */
#pragma once

#include <SDL.h>

class InputManager {
	
private:
	static InputManager* sInstance;

	const Uint8* mKeyboardStates;

public:
	static InputManager* Instance();
	static void Release();

	bool KeyDown(SDL_Scancode scanCode);

	void Update();

private:
	InputManager();
	~InputManager();
};