/*
 * File: State.hpp
 * Folder: StateManager
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:42:14 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include "Window.hpp"
#include "StateAction.hpp"
#include "Event/EventHandler.hpp"

class State
{

protected:
	sf::Time		mDeltaTime = sf::seconds(1.f / 128.f);
	StateAction		mStateReturnAction = StateAction::POP;

	bool			mIsInit = false;
	bool			mIsActive = true;
	Window			*mWindow = NULL;


public:

	virtual				~State() {}

	virtual void		Init() = 0;
	virtual StateAction	Run();
	virtual void		HandleEvents() = 0;
	virtual void		Update() = 0;
	virtual void		Render() = 0;

	bool				IsInitiated(){return (mIsInit);}
};


