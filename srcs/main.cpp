#include "Core.hpp"

void	Init()
{
	Console::Init();
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