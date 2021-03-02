#pragma once

#include "Window.hpp"
#include "mfGUI.hpp"

class Console
{
private:
	Console(/* args */) {}
	~Console() {}
	static mf::Container	*mConsoleWidget;

public:
	

	static void		Init();
	static void		InitUI();
	static void		ToggleConsole();
};

