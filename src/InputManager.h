/**
 * @file		InputManager.cpp
 * @date		19-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Handles all Input related functionality for keyboard and mouse.
 *				(To be expanded later to handle touch and contoller input)
 */
#pragma once

#include <SDL.h>
#include "MathHelper.h"

class InputManager {
public:
	/**
	 * @brief		MOUSE_BUTTON enum to discribe left mouse button, right mouse button, .. and so on
	 */
	enum MOUSE_BUTTON { left = 0, right, middle, back, forward };

private:
	// Needed to make InputManager a singleton class
	static InputManager* sInstance;

	// Holds the keyboard key state of the last frame (used to catch key press and key release events)
	Uint8* mPrevKeyboardState;
	// Holds the keyboard key state of the current frame
	const Uint8* mKeyboardState;
	// The number of keys in the mKeyboardState array (used to copy the current keyboard state into the previous keyboard state)
	int mKeyLength;

	// Holds the mouse button state of the last frame (used to catch mouse button press and release events)
	Uint32 mPrevMouseState;
	// Holds the mouse button state of the current frame
	Uint32 mMouseState;

	// Used to retrieve the current mouse position using SDL_GetMouseState
	int mMouseXPos;
	int mMouseYPos;

public:
	/**
	 * brief		Returns a pointer to the class instance
	 */
	static InputManager* Instance();
	/**
	 * @brief		Releases the class instance and sets it back to NULL
	 */
	static void Release();

	/**
	 * @brief		Returns true as long as the key given in scanCode is held down
	 */
	bool KeyDown(SDL_Scancode scanCode);
	/**
	 * @brief		Returns true only on the frame that the key given in scanCode is pressed down
	 */
	bool KeyPressed(SDL_Scancode scanCode);
	/**
	 * @brief		Returns true only on the frame that the key given in scanCode is released
	 */
	bool KeyReleased(SDL_Scancode scanCode);

	/**
	 * @brief		Returns true as long as the given mouse button is held down
	 */
	bool MouseButtonDown(MOUSE_BUTTON button);
	/**
	 * @brief		Returns true only on the frame that the given mouse button is pressed
	 */
	bool MouseButtonPressed(MOUSE_BUTTON button);
	/**
	 * @brief		Returns true only on the frame that the given mouse button is released
	 */
	bool MouseButtonReleased(MOUSE_BUTTON button);

	/**
	 * @brief		Returns a Vector2 containing the current mouse position on screen
	 */
	Vector2 MousePos();

	/**
	 * @brief		Updates the Input States (should be called once per frame before any input check)
	 */
	void Update();
	/**
	 * @brief		Sets the current frame's key states as the previous key states (to be called in the LateUpdate)
	 *				No input checks should be made in the current frame after this function is called
	 */
	void UpdatePrevInput();

private:
	/**
	 * @brief		Contructor is private so that Instance() must be used to get an instance when needed
	 */
	InputManager();
	/**
	 * @brief		Destructor is private so that the instance can only be destroyed using Release()
	 */
	~InputManager();
};
