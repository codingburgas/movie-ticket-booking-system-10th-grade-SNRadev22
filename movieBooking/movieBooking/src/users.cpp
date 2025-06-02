#include "../include/users.h"
#include "../include/Utility.h"
#include <fstream>
#include<string>
#include <iostream>

User user;

std::string getUserInput()
{
	std::string userInput;
	while (true)
	{
		std::getline(std::cin, userInput);
		if (userInput.empty())
		{
			std::cerr << "Input cannot be empty." << std::endl;
		}
		else
		{
			return userInput;
		}
	}
}

bool exists(const std::string fileName, std::string input)
{
	std::ifstream file;
	std::string toCheck;
	file.open(fileName);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		file.close();
		return false;
	}
	else
	{
		while (std::getline(file, toCheck))
		{
			if (toCheck == input)
			{
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
}

void addToFile(const std::string& fileName, std::ios_base::openmode mode, const std::string& input)
{
	std::ofstream file;
	file.open(fileName, mode);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}
	else
	{
		file << input << std::endl;
		file.close();
	}

}

bool validAccount(const std::string& fileName, std::string usernameToFind, std::string passwordToFind)
{
	std::ifstream file;
	file.open(fileName);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return false;
	}
	else
	{
		std::string username, password, rankStr;
		while (std::getline(file, username))
		{
			if (username == usernameToFind)
			{
				std::getline(file, password);
				if (password == passwordToFind)
				{
					std::getline(file, rankStr);
					setRank(rankStr);
					file.close();
					return true;
				}
			}
		}
		file.close();
		return false;
	}
}