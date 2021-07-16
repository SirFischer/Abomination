/*
 * File: Map.cpp
 * Folder: Map
 * File Created: Monday, 15th March 2021 9:12:09 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:25:41 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "Map.hpp"

Map::Map()
{
	mSeed = time(0);
}

Map::~Map()
{

}

void		Map::AddRoom(const Room &tRoom)
{
	mRooms.push_back(tRoom);
}

void		Map::AddObject(const Object &tObject)
{
	mObjects.push_back(tObject);
}


void		Map::SetRenderPosition(sf::Vector2i tRenderPosition)
{
	mRenderPosition = tRenderPosition;
}


void		Map::Draw(Window *tWindow)
{
	for (auto &i : mRooms)
	{
		i.Draw(tWindow);
	}
}
