#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager/ResourceManager.hpp"

class Object
{
private:
	sf::Texture		mTexture;
	sf::Sprite		mSprite;

public:
	Object(/* args */) {}
	~Object() {}

	void			LoadTextureFromFile(std::string tPath);
	void			LoadTextureFromFile(sf::Texture *tTexture);
};