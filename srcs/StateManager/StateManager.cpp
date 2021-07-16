/*
 * File: StateManager.cpp
 * Folder: StateManager
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:26:54 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "StateManager.hpp"


StateManager::StateManager(Window *tWindow)
{
	mWindow = tWindow;
	mStates.push(new MenuState(mWindow)); //Entry State
}

StateManager::~StateManager()
{

}

void		StateManager::Run()
{
	StateAction	action = StateAction::POP;

	while (mStates.size())
	{
		if (!mStates.top()->IsInitiated())
			mStates.top()->Init();
		action = mStates.top()->Run();

		switch (action)
		{
		case StateAction::EXIT:
			while (mStates.size())
			{
				delete mStates.top();
				mStates.pop();
			}
			break;

		case StateAction::POP:
			delete mStates.top();
			mStates.pop();
			break;
		
		case StateAction::GAME:
			mStates.push(new GameState(mWindow));
			break;

		case StateAction::MENU:
			mStates.push(new MenuState(mWindow));
			break;

		case StateAction::OPTIONS:
			mStates.push(new OptionsState(mWindow));
			break;

		default:
			delete mStates.top();
			mStates.pop();
			break;
		}
	}
}