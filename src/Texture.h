/**
 * @file		Texture.cpp
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		The base class for all textures to be rendered on screen
 *				Can load full textures, or clipped textures from a spritesheet
 * 				or convert a string into a texture to be rendered
 */
#pragma once

#include "GameEntity.h"
#include "AssetManager.h"

class Texture : public GameEntity {

protected:
	// The SDL_Texture to be rendered
	SDL_Texture* mTex;

	// Used to render the texture
	Graphics* mGraphics;

	// Width of the texture
	int mWidth;
	// Height of the texture
	int mHeight;

	// True if the texture is loaded from a spritesheet
	bool mClipped;
	// Is used to render the texture on the screen
	SDL_Rect mRenderRect;
	// Is used to clip the texture from a spritesheet
	SDL_Rect mClipRect;


public:
	/**
	 * @brief		Loads a whole texture from a file (relative to the exe path)
	 *				Note: For spritesheets use the other contructor
	 */
	Texture(std::string filename);
	/**
	 * @brief		Loads a texture from from file (relative to the exe path)
	 *				Supports spritesheets
	 *
	 * @param x 	Starting pixel's X on the spritesheet
	 * @param y		Starting pixel's Y on the spritesheet
	 * @param w 	The width of the clipped sprite
	 * @param h 	The height of the clipped sprite
	 */
	Texture(std::string filename, int x, int y, int w, int h);
	/**
	 * @brief		Converts the given text into a texture to be rendered
	 *				Note: fontpath is relative to the exe path
	 *
	 * @param size  The size of the text to be rendered
	 * @param color The color of the text to be rendered
	 */
	Texture(std::string text, std::string fontPath, int size, SDL_Color color);
	~Texture();

	/**
	 * @brief		Called to render the texture to the screen
	 */
	virtual void Render();
};