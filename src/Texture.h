/**
 * @file		Texture.cpp
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Texture animation handler
 */
#pragma once

#include "GameEntity.h"
#include "AssetManager.h"

class Texture : public GameEntity {

protected:
	SDL_Texture* mTex;

	Graphics* mGraphics;

	int mWidth;
	int mHeight;

	bool mClipped;
	SDL_Rect mRenderRect;
	SDL_Rect mClipRect;


public:
	Texture(std::string filename);
	Texture(std::string filename, int x, int y, int w, int h);
	Texture(std::string text, std::string fontPath, int size, SDL_Color color);
	~Texture();

	virtual void Render();
};