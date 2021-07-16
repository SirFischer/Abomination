/*
 * File: GameState.cpp
 * Folder: Game
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:25:56 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "GameState.hpp"

#include "Window.hpp"

GameState::GameState(Window *tWindow)
{
	mWindow = tWindow;
	mWindow->HideCursor();

	//TESTMAP
	Room room;
	room.LoadFromFile("assets/maps/testmap/basicTest.map");
	mMap.AddRoom(room);
}

GameState::~GameState()
{
	mWindow->ShowCursor();
}

void		GameState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	Console::InitUI();
	/**
	 * INIT STATE AND GUI
	 **/
}

void		GameState::HandleEvents()
{
	sf::Event event;
	while (mWindow->HandleEvent(event))
	{
		EventHandler::HandleEvent(event);
		mf::GUI::HandleEvent(event);
		if (event.type == sf::Event::Resized)
			mWindow->ResetView(true);
		if (event.type == sf::Event::Closed)
		{
			mIsActive = false;
			mStateReturnAction = StateAction::EXIT;
		}
	}
}

void		GameState::Update()
{
	Console::Update();
	if (EventHandler::GetEventState(EventHandler::eEvent::OPEN_CONSOLE))
	{
		Console::ToggleConsole();
		if (Console::IsOpen())
			mWindow->ShowCursor();
		else
			mWindow->HideCursor();
		EventHandler::SetEventState(EventHandler::eEvent::OPEN_CONSOLE, false);
	}
	mPlayer.Update();
}

void		GameState::Render()
{
	mWindow->Clear(sf::Color::White);

	//RENDER YOUR STUFF
	mMap.Draw(mWindow);
	mPlayer.Render(mWindow);
	
	mf::GUI::Render();
	mWindow->Render();
}