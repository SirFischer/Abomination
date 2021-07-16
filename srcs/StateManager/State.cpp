/*
 * File: State.cpp
 * Folder: StateManager
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:26:48 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "State.hpp"

StateAction			State::Run()
{
	sf::Time		mElapsedTime = sf::seconds(0);
	sf::Clock		mClock;

	while (mIsActive)
	{
		while (mElapsedTime.asSeconds() > mDeltaTime.asSeconds())
		{
			HandleEvents();
			Update();
			mElapsedTime -= mDeltaTime;
		}
		Render();
		mElapsedTime += mClock.restart();
	}
	return (mStateReturnAction);
}