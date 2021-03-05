#include "Console.hpp"

Console::eCommandStatus		Help(std::vector<std::string> tParams)
{
	if (tParams.size() == 0)
	{
		Console::AddString("Available commands:");
		for (auto &command : Console::GetCommands())
		{
			Console::AddString(command.first + " - " + command.second.mHelpShort);
		}
	}
	else
	{
		for (auto &command : tParams)
		{
			if (Console::GetCommands().count(command))
				Console::AddString(command + " - " + Console::GetCommands()[command].mHelpLong);
			else
				Console::AddString(command + " does not exist...");
		}
	}
	return (Console::eCommandStatus::SUCCESS);
}

Console::eCommandStatus		Clear(std::vector<std::string> tParams)
{
	(void)tParams;
	Console::ClearConsole();
	return (Console::eCommandStatus::SUCCESS);
}

void						Console::LoadInternalCommands()
{
	AddCommand((sCommand){.mFunction = Help,
				.mHelpShort = "List available commands.",
				.mHelpLong = "List available commands. Use help [command] to get more information about the command."},
				"help");
	AddCommand((sCommand){.mFunction = Clear,
				.mHelpShort = "Clears the console.",
				.mHelpLong = "Clears the console... that's it!"},
				"clear");
}
