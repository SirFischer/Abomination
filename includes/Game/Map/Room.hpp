#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Room
{
private:
	std::map<uint32_t, std::string>		mPaths;
	sf::Sprite							mSprite;

public:
	Room(/* args */) {}
	~Room() {}
	
	void								LoadFromFile(std::string tPath);
};