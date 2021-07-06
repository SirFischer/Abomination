#include "Room.hpp"

void		Room::LoadSignature(std::stringstream &ss, std::string &line, std::string &token)
{
	std::getline(ss, token, '=');
	std::stringstream ss2(token);
	std::getline(ss2, line, ' ');
	uint32_t signature = std::stoi(line);
	std::getline(ss2, line, ' ');
	mSignaturePaths[signature] = line;
}

void		Room::LoadObject(std::stringstream &ss, std::string &line, std::string &token)
{
	mObjects.emplace_back();
	std::getline(ss, token, '=');
	std::stringstream ss2(token);
	std::getline(ss2, line, ' ');
	uint32_t signature = std::stoi(line);
	mObjects.back().SetSignature(signature);
}

void		Room::LoadPosition(std::stringstream &ss, std::string &line, std::string &token)
{
	double	position = 0.0;

	std::getline(ss, token, '=');
	std::stringstream ss2(token);
	std::getline(ss2, line, ' ');
	position = std::stod(line);
	std::getline(ss2, line, ' ');
	mObjects.back().SetPosition(sf::Vector2f(position * 0.64, std::stod(line) * 0.64));
}

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
		if (token == "elem")
			LoadObject(ss, line, token);
		else if (token == "pos")
			LoadPosition(ss, line, token);
		else if (token == "signature")
			LoadSignature(ss, line, token);
	}
}


void		Room::Draw(Window *tWindow)
{
	for (auto &i : mSignaturePaths)
	{
		mSprite.setTexture(*(ResourceManager::LoadTexture(i.second)));
		for (auto &j : mObjects)
		{
			if (i.first == j.GetSignature())
			{
				mSprite.setPosition(j.GetPosition());
				tWindow->Draw(mSprite);
			}
		}
	}
}