/*
 * File: StateManager.hpp
 * Folder: StateManager
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:42:29 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include "States.hpp"
#include <stack>

class StateManager
{
private:
	std::stack<State *>	mStates;

	Window				*mWindow = NULL;

public:
	StateManager(Window *tWindow);
	~StateManager();

	void		Run();
};
