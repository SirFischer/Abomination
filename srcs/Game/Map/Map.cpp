#include "Map.hpp"

Map::Map()
{
	srand(time(0));
	mSeed = (rand() % 1000) + 1;
}

Map::~Map()
{

}