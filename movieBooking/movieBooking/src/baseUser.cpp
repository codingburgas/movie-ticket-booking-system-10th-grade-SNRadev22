#include "../include/baseUser.h"
#include "../include/Utility.h"
#include <fstream>
#include<string>
#include <iostream>

BaseUser baseUser;

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
		baseUser.userRank = USER;
		std::cout << "User" << std::endl;
	}
	else if (rankStr == "ADMIN")
	{
		baseUser.userRank = ADMIN;
		std::cout << "Admin" << std::endl;
	}
	else if (rankStr == "MANAGER")
	{
		baseUser.userRank = MANAGER;
		std::cout << "Manager" << std::endl;
	}
}

bool BaseUser::validAccount(const std::string& fileName, std::string usernameToFind, std::string passwordToFind)
{
	std::ifstream file(fileName);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return false;
	}

	std::string email, skip, username, password, rankStr;
	while (std::getline(file, email))
	{
		std::getline(file, skip);
		std::getline(file, username);
		std::getline(file, password);
		std::getline(file, rankStr);

		if (username == usernameToFind && password == passwordToFind)
		{
			setEmail(email);
			setUsername(username);
			setPassword(password);
			setRank(rankStr);
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}