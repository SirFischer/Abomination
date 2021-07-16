/*
 * File: ResourceManager.hpp
 * Folder: ResourceManager
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:42:03 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <memory>
#include <iostream>

typedef	std::map<std::string, std::shared_ptr<sf::Font>> FontList;
typedef	std::map<std::string, std::shared_ptr<sf::Texture>> TextureList;
typedef std::map<std::string, std::shared_ptr<sf::SoundBuffer>> SoundBufferList;

class ResourceManager
{
private:
	ResourceManager(/* args */);
	~ResourceManager();

	static FontList			mFontResources;
	static TextureList		mTextureResources;
	static SoundBufferList  mSoundBufferResources;

public:

	static sf::Font			*LoadFont(const std::string &tPath);
	static sf::Texture		*LoadTexture(const std::string &tPath);
	static sf::SoundBuffer	*LoadSoundBuffer(const std::string &tPath);

};
