#pragma once

#include "Window.hpp"
#include "mfGUI.hpp"

class Console
{
private:
	Console(/* args */) {}
	~Console() {}
	static mf::Container	*mConsoleWidget;
	static mf::Text			*mConsoleTextBox;
	static mf::Text			*mConsoleInputBox;

public:
	

	static void		Init();
	static void		InitUI();
	static void		ToggleConsole();
};

