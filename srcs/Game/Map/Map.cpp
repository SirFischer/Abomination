#include "Map.hpp"

Map::Map()
{
	mSeed = time(0);
}

Map::~Map()
{

}

void		Map::Draw(Window *tWindow)
{
	for (auto &i : mRooms)
	{
		i.Draw(tWindow);
	}
}
