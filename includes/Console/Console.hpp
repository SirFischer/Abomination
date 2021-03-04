#pragma once

#include <functional>
#include <map>
#include <vector>
#include <sstream>

#include "Window.hpp"
#include "mfGUI.hpp"
#include "Event/EventHandler.hpp"

class Console
{
public:
	enum class eCommandStatus {
		SUCCESS,
		FAILURE,
		BAD_COMMAND,
		BAD_ARGUMENTS
	};
	typedef std::function<Console::eCommandStatus(std::vector<std::string> tParams)> tCommandFunction;
	struct sCommand {
		Console::tCommandFunction				mFunction;
		std::string								mHelpShort;
		std::string								mHelpLong;
	};
private:
	Console(/* args */) {}
	~Console() {}

	/**
	 * GUI
	 **/
	static mf::Container						*mConsoleWidget;
	static mf::Text								*mConsoleTextBox;
	static mf::Text								*mConsoleInputBox;

	/**
	 * Data
	 **/
	static std::map<std::string, sCommand>		mCommands;

	static void									LoadInternalCommands();

public:
	static void									Init();
	static void									InitUI();
	static void									ToggleConsole();

	static void									AddCommand(sCommand tCommand, std::string tCommandName);

	static eCommandStatus						ProcessCommand(std::string tCommand);
	
	static void									Update();

	static void									AddString(std::string tMessage);

	/**
	 * GETTERS
	 **/
	static std::map<std::string, sCommand>		&GetCommands(){return (mCommands);}
	static bool									IsOpen(){return (!mConsoleWidget->IsDisabled());}
};

//Internal Console Commands

