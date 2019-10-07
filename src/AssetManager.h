/**
 * @file		AssetManager.cpp
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Used to load all assets used in the game,
 *				Caches all loaded assets so that nothing is loaded more than once
 */
#pragma once

#include "Graphics.h"
#include <SDL_mixer.h>
#include <map>

class AssetManager {

private:
	// Needed to make AssetManager a singleton class
	static AssetManager* sInstance;

	// Used to cache all loaded images
	std::map<std::string, SDL_Texture*> mTextures;
	// Used to cache all rendered text converted to textures
	std::map<std::string, SDL_Texture*> mText;
	// Used to cache all loaded fonts
	std::map<std::string, TTF_Font*> mFonts;
	// Used to cache all loaded music files
	std::map<std::string, Mix_Music*> mMusic;
	// Used to cache all loaded sound effect files 
	std::map<std::string, Mix_Chunk*> mSFX;

public:
	/**
	 * @brief		Returns a pointer to the class instance
	 */
	static AssetManager* Instance();
	/**
	 * @brief		Releases the class instance and sets it back to NULL
	 */
	static void Release();

	/**
	 * @brief		Should be used when any texture needs to be loaded from file
	 *				If the texture was not previously loaded, it is loaded from file then cached are returned
	 *				otherwise, the already cached texture is returned
	 */
	SDL_Texture* GetTexture(std::string filename);

	/**
	 * @brief		If the given text with the same font and size and color was renderer previously, the cached texture is returned
	 *				If it has not been rendered before, the text is rendered and cached, then returned to be reused again later
	 *
	 * @param size	Size of the font
	 * @param color Color of the font
	 */
	SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);

	/**
	 * @brief		If the music file was opened before, the cached Mix_Music* is returned
	 *				otherwise, the file is loaded and converted into a Mix_Music* and cached then returned
	 */
	Mix_Music* GetMusic(std::string filename);

	/**
	 * @brief		If the SFX file was opened before, the cached Mix_Chunk* is returned
	 * 				otherwise, the file is loaded and converted into a Mix_Chunk* and cached then returned
	 */
	Mix_Chunk* GetSFX(std::string filename);

private:
	/**
	 * @brief		Contructor is private so that Instance() must be used to get an instance when needed
	 */
	AssetManager();

	/**
	 * @brief 		Destructor is private so that the instance can only be destroyed using Release()
	 */
	~AssetManager();

	/**
	 * @brief		If the same font and size was loaded before, the cached TTF_Font* is returned
	 *				otherwise, the font is loaded and cached, then returned
	 *
	 * @param size	Size of the font
	 */
	TTF_Font* GetFont(std::string filename, int size);
};