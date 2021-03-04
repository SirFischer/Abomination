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
				return (Console::eCommandStatus::BAD_ARGUMENTS);
		}
	}
	return (Console::eCommandStatus::SUCCESS);
}

void						Console::LoadInternalCommands()
{
	AddCommand((sCommand){.mFunction = Help,
				.mHelpShort = "List available commands.",
				.mHelpLong = "List available commands. Use help [command] to get more information about the command."},
				"help");
}
