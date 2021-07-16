/*
 * File: Map.hpp
 * Folder: Map
 * File Created: Monday, 15th March 2021 2:09:46 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:23:58 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <vector>
#include <random>

#include "Window.hpp"
#include "Room.hpp"
#include "Object.hpp"

class Map
{
public:
	Map(/* args */);
	~Map();

	void					AddRoom(const Room &tRoom);
	void					AddObject(const Object &tObject);

	/**
	 * The render position is used in addition to the seed to generate the map
	 * and should be set relative to the position of the camera/player.
	 **/
	void					SetRenderPosition(sf::Vector2i tRenderPosition);

	void					Draw(Window *tWindow);
private:

	uint32_t				mSeed = 0;
	std::vector<Room>		mRooms;
	std::vector<Object>		mObjects;
	sf::Vector2i			mRenderPosition = sf::Vector2i(0, 0);
};