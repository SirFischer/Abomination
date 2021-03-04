#pragma once

#include "State.hpp"
#include "Console.hpp"

class GameState : public State
{
private:
	/* data */
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

