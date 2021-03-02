#include "Console.hpp"

mf::Container		*Console::mConsoleWidget = NULL;

void		Console::Init()
{
	
}

void		Console::InitUI()
{
	mConsoleWidget = mf::Container::Create();
	mConsoleWidget->SetDisabled(true);
	mConsoleWidget->SetIndex(1);
	mConsoleWidget->SetSizePercentage(true)->SetSize(100, 40);
	mConsoleWidget->SetBackground(sf::Color(57, 57, 57, 200));
	
	mf::GUI::AddWidget(mConsoleWidget);
}


void		Console::ToggleConsole()
{
	mConsoleWidget->SetDisabled(!mConsoleWidget->IsDisabled());
}


