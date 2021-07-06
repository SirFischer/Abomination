#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Window.hpp"

class Room
{
private:
	std::map<uint32_t, std::string>		mSignaturePaths;
	std::vector<Object>					mObjects;
	sf::Sprite							mSprite;

	/**
	 * Parsing functions
	 **/
	void								LoadSignature(std::stringstream &ss, std::string &line, std::string &token);
	void								LoadObject(std::stringstream &ss, std::string &line, std::string &token);
	void								LoadPosition(std::stringstream &ss, std::string &line, std::string &token);

public:
	Room(/* args */) {}
	~Room() {}
	
	void								LoadFromFile(std::string tPath);

	void								Draw(Window *tWindow);
};