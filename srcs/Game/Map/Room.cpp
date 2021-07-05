#include "Room.hpp"



void		Room::LoadFromFile(std::string tPath)
{
	std::string		line;
	std::fstream	file;
	file.open(tPath, std::ios_base::in);
	if (!file.is_open())
	{
		std::cout << "Failed to open " << tPath << std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			token;
		std::getline(ss, token, '=');
		if (token == "signature")
		{
			std::getline(ss, token, '=');
			std::stringstream ss2(token);
			std::getline(ss2, line, ' ');
			uint32_t signature = std::stoi(line);
			std::getline(ss2, line, ' ');
			mPaths[signature] = line;
			continue ;
		}
	}

	//check content
	for (auto &i : mPaths)
		std::cout << i.first << " - " <<  i.second << std::endl;
}
