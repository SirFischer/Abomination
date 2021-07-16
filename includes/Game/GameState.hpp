/*
 * File: GameState.hpp
 * Folder: Game
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:41:37 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include "State.hpp"
#include "Console.hpp"

#include "Player.hpp"
#include "Map/Map.hpp"

class GameState : public State
{
private:
	Player		mPlayer;
	Map			mMap;

public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

