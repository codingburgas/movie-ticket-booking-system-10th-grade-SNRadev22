#include "../include/baseUser.h"
#include "../include/Utility.h"
#include <fstream>
#include<string>
#include <iostream>

std::string BaseUser::getEmail()
{
	return email;
}
std::string BaseUser::getUsername()
{
	return username;
}
std::string BaseUser::getPassword()
{
	return password;
}
rank BaseUser::getRank()
{
	return userRank;
}

void BaseUser::setEmail(std::string newEmail)
{
	email = newEmail;
}
void BaseUser::setUsername(std::string newUsername)
{
	username = newUsername;
}
void BaseUser::setPassword(std::string newPassword)
{
	password = newPassword;
}
void BaseUser::setRank(std::string rankStr)
{
	if (rankStr == "USER")
	{
		user.userRank = USER;
		std::cout << "User" << std::endl;
	}
	else if (rankStr == "ADMIN")
	{
		user.userRank = ADMIN;
		std::cout << "Admin" << std::endl;
	}
	else if (rankStr == "MANAGER")
	{
		user.userRank = MANAGER;
		std::cout << "Manager" << std::endl;
	}
}

bool BaseUser::validAccount(const std::string& fileName, std::string usernameToFind, std::string passwordToFind)
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