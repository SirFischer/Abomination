#pragma once

#include <vector>
#include <random>

#include "Window.hpp"
#include "Room.hpp"
#include "Object.hpp"

class Map
{
private:

	uint32_t				mSeed = 0;
	std::vector<Room>		mRooms;
	std::vector<Object>		mObjects;

public:
	Map(/* args */);
	~Map();

	void					AddRoom(Room &tRoom){mRooms.push_back(tRoom);};
	void					AddObject(Object &tObject){mObjects.push_back(tObject);};

	void					Draw(Window *tWindow);
};