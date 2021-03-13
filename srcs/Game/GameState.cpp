#include "GameState.hpp"

GameState::GameState(Window *tWindow)
{
	mWindow = tWindow;
	mWindow->HideCursor();
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
	mWindow->Clear(sf::Color::Green);

	//RENDER YOUR STUFF
	mPlayer.Render(mWindow);
	
	mf::GUI::Render();
	mWindow->Render();
}