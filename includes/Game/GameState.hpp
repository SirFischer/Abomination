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

