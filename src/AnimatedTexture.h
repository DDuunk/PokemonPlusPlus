/**
 * @file		AnimatedTexture.cpp
 * @date		20-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Extends the Texture class' functionality to handle animations
 *			Uses the Texture class' spritesheet constructor
 */
#pragma once

#include "Timer.h"
#include "Texture.h"

class AnimatedTexture : public Texture {

public:
	/**
	 * @brief		Wrap mode used by the animated
	 *			once / loop
	 */
	enum WRAP_MODE { once = 0, loop = 1 };

	/**
	 * @brief		The way the animation sprites are arranged in the spritesheet
	 *			Horizontal / Vertical
	 */
	enum ANIM_DIR { horizontal = 0, vertical = 1 };

private:

	// Used to get the deltatime to update the animation
	Timer* mTimer;

	// The first frame's starting pixel's on the spritesheet
	int mStartX;
	int mStartY;

	// Used to keep track of length current animation
	float mAnimationTimer;
	// Used to determine animation speed
	float mAnimationSpeed;
	// Stores how long each animation frame should be on screen
	float mTimePerFrame;

	// Stores number of animation frames in the animation
	int mFrameCount;

	// Stores the wrap mode
	WRAP_MODE mWrapMode;
	// Stores the animation direction
	ANIM_DIR mAnimationDirection;

	// True if the wrap mode is once and the last frame of the animation is reached
	bool mAnimationDone;

public:
	/**
	 * @brief			Loads a texture from a file (relative to the exe path)
	 *				Supports spritesheets
	 *
	 * @param x			Starting pixel's X on the spritesheet
	 * @param y			Starting pixel's y on the spritesheet
	 * @param w			Width of clipped sprite
	 * @param h			Height of clipped sprite
	 * @param frameCount		Number of frames in animation
	 * @param animationSpeed	How long it takes to run animation
	 * @param mAnimationDirection	How animation sprites are arranged in the spritesheet
	 */
	AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir);
	~AnimatedTexture();

	/**
	 * @brief		Sets wrap mode of animation
	 */
	void WrapMode(WRAP_MODE mode);

	/**
	 * @brief		Updates animation frames and loop animation if needed
	 */
	void Update();
};
