/*
 * File: main.cpp
 * Folder: srcs
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:27:17 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "Core.hpp"

void	Init()
{
	Console::Init();
	EventHandler::Init();
	EventHandler::LoadDefaultBindings();
}

int		main( void )
{
	Window		window;

	StateManager	stateManager(&window);
	try
	{
		Init();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	stateManager.Run();

	return (0);
}