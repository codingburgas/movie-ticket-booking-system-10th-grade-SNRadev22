#include "../include/users.h"
#include "../include/Utility.h"
#include <fstream>
#include<string>
#include <iostream>

std::string User::getEmail()
{
	return email;
}
std::string User::getUsername()
{
	return username;
}
std::string User::getPassword()
{
	return password;
}
rank User::getRank()
{
	return userRank;
}

void User::setEmail(std::string newEmail)
{
	email = newEmail;
}
void User::setUsername(std::string newUsername)
{
	username = newUsername;
}
void User::setPassword(std::string newPassword)
{
	password = newPassword;
}
void User::setRank(std::string rankStr)
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

bool User::validAccount(const std::string& fileName, std::string usernameToFind, std::string passwordToFind)
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