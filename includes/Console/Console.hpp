#pragma once

#include <functional>
#include <map>
#include <vector>
#include <sstream>

#include "mfGUI.hpp"
#include "Event/EventHandler.hpp"
/*
 * File: Console.hpp
 * Folder: Console
 * File Created: Tuesday, 2nd March 2021 3:47:28 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:39:53 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

class Console
{
public:
	enum class eCommandStatus {
		SUCCESS,
		FAILURE,
		BAD_COMMAND,
		BAD_ARGUMENTS
	};
	typedef std::function<Console::eCommandStatus(const std::vector<std::string> &tParams)> tCommandFunction;
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

	static void									AddCommand(sCommand tCommand, const std::string &tCommandName);

	static eCommandStatus						ProcessCommand(std::string tCommand);
	
	static void									Update();

	static void									AddString(const std::string &tMessage);
	static void									ClearConsole();

	/**
	 * GETTERS
	 **/
	static std::map<std::string, sCommand>		&GetCommands(){return (mCommands);}
	static bool									IsOpen(){return (!mConsoleWidget->IsDisabled());}
};

//Internal Console Commands

