#include "Console.hpp"

mf::Container									*Console::mConsoleWidget = NULL;
mf::Text										*Console::mConsoleTextBox = NULL;
mf::Text										*Console::mConsoleInputBox = NULL;

std::map<std::string, Console::sCommand>		Console::mCommands = std::map<std::string, Console::sCommand>();

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

	mConsoleTextBox = mf::Text::Create("assets/fonts/Roboto-Regular.ttf", "");
	mConsoleTextBox->SetSizePercentage(true)->SetSize(98, 80);
	mConsoleTextBox->SetPositionPercentage(true)->SetPosition(1, 1);
	mConsoleTextBox->SetBackgroundColor(sf::Color(37, 37, 37, 200));
	mConsoleTextBox->SetOutlineColor(sf::Color(100, 100, 100, 255));
	mConsoleTextBox->SetOutlineThickness(1);
	mConsoleWidget->AddWidget(mConsoleTextBox);

	mConsoleInputBox = mf::Text::Create("assets/fonts/Roboto-Regular.ttf", "");
	mConsoleInputBox->SetSizePercentage(true)->SetSize(98, 10);
	mConsoleInputBox->SetPositionPercentage(true)->SetPosition(1, 85);
	mConsoleInputBox->SetBackgroundColor(sf::Color(37, 37, 37, 200));
	mConsoleInputBox->SetOutlineColor(sf::Color(100, 100, 100, 255));
	mConsoleInputBox->SetOutlineThickness(1);
	mConsoleInputBox->SetCharacterSize(12);
	mConsoleInputBox->EnableEdit();
	mConsoleWidget->AddWidget(mConsoleInputBox);
	
}

void		Console::ToggleConsole()
{
	mConsoleWidget->SetDisabled(!mConsoleWidget->IsDisabled());
}

void		Console::AddCommand(sCommand tCommand, std::string tCommandName)
{
	mCommands[tCommandName] = tCommand;
}


void		Console::HandleEvent()
{
	//HANDLE INPUT EVENTS
	if (EventHandler::GetEventState(EventHandler::eEvent::CONFIRM))
	{
		EventHandler::SetEventState(EventHandler::eEvent::CONFIRM, false);
		std::string command = mConsoleInputBox->GetString();
		//Execute command
		if (command == "PLAY\n")
		{
			mCommands["PLAY"].mFunction(std::vector<std::string>());
			mConsoleTextBox->AddText("Command ran succesfully!\n");
		}
		else
			mConsoleTextBox->AddText("Command failed...\n");
		mConsoleInputBox->SetText("");
	}
}



