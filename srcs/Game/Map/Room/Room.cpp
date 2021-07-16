/*
 * File: Room.cpp
 * Folder: Room
 * File Created: Monday, 15th March 2021 5:03:58 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:25:30 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "Room.hpp"

void		Room::SetAdjacency(LegalAdjacency tLegalAdjencency)
{
	mLegalAdjancency |= (uint8_t)tLegalAdjencency;
}

void		Room::Draw(Window *tWindow)
{
	for (auto &i : mSignaturePaths)
	{
		mSprite.setTexture(*(ResourceManager::LoadTexture(i.second)));
		for (auto &j : mObjects)
		{
			if (i.first == j.GetSignature())
			{
				mSprite.setPosition(j.GetPosition());
				tWindow->Draw(mSprite);
			}
		}
	}
}