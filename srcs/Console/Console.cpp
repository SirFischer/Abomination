#include "Console.hpp"

mf::Container									*Console::mConsoleWidget = NULL;
mf::Text										*Console::mConsoleTextBox = NULL;
mf::Text										*Console::mConsoleInputBox = NULL;

std::map<std::string, Console::sCommand>		Console::mCommands = std::map<std::string, Console::sCommand>();

void		Console::Init()
{
	LoadInternalCommands();
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
	mConsoleTextBox->SetCharacterSize(14);
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

Console::eCommandStatus		Console::ProcessCommand(std::string tCommand)
{
	std::vector<std::string>	parameters;
	std::replace(tCommand.begin(), tCommand.end(), '\t', ' ');
	std::stringstream			ss(tCommand);
	std::string					command;
	std::string					tmp;
	ss >> command;
	while (ss >> tmp)
	{
		parameters.push_back(tmp);
	}
	if (mCommands.count(command))
	{
		return (mCommands[command].mFunction(parameters));
	}
	else
	{
		Console::AddString(command + " is not a valid command!");
		return (eCommandStatus::FAILURE);
	}
		
}


void		Console::Update()
{
	//HANDLE INPUT EVENTS
	if (EventHandler::GetEventState(EventHandler::eEvent::CONFIRM))
	{
		EventHandler::SetEventState(EventHandler::eEvent::CONFIRM, false);
		std::string command = mConsoleInputBox->GetString();
		command.pop_back();
		time_t	currentTime = time(NULL);
		std::tm	*ltm = localtime(&currentTime);
		Console::AddString(((ltm->tm_hour <= 9) ? "0" : "") + std::to_string(ltm->tm_hour) + ":" +
							((ltm->tm_min <= 9) ? "0" : "") + std::to_string(ltm->tm_min) + ":" +
							((ltm->tm_sec <= 9) ? "0" : "") + std::to_string(ltm->tm_sec) + " - " + command);
		//Execute command
		ProcessCommand(command);
		mConsoleInputBox->SetText("");
		Console::AddString("");
	}
}

void		Console::AddString(std::string tMessage)
{
	mConsoleTextBox->AddText(tMessage + '\n');
}




