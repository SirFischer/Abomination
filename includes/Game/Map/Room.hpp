/*
 * File: Room.hpp
 * Folder: Map
 * File Created: Monday, 15th March 2021 4:50:16 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 7:25:14 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Window.hpp"

/**
 * This Class represents only a possible design for a room.
 * With the help of the list of legal adjacencies it will be combined
 * with other tiles to generate the caves.
 **/
class Room
{
public:
	enum class LegalAdjacency
	{
		NONE	=	0,
		TOP		=	1,
		BOTTOM	=	1 << 1,
		LEFT	=	1 << 2,
		RIGHT	=	1 << 3
	};

	Room(/* args */) {}
	~Room() {}
	
	void								LoadFromFile(std::string tPath);

	/**
	 * Setters
	 **/
	void								SetAdjacency(LegalAdjacency tLegalAdjancency);

	void								Draw(Window *tWindow);
	
private:
	std::map<uint32_t, std::string>		mSignaturePaths;
	std::vector<Object>					mObjects;
	sf::Sprite							mSprite;

	uint8_t								mLegalAdjancency = 0;

	/**
	 * Parsing functions
	 **/
	void								LoadSignature(std::stringstream &ss, std::string &line, std::string &token);
	void								LoadObject(std::stringstream &ss, std::string &line, std::string &token);
	void								LoadPosition(std::stringstream &ss, std::string &line, std::string &token);
};