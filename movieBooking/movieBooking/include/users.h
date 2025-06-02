#pragma once
#include<string>
#include <ios>

struct User
{
	std::string email;
	std::string username;
	std::string password;
	enum rank {USER, ADMIN, MANAGER};
	rank userRank;
};

extern User user;

std::string getUserInput();

bool exists(const std::string fileName, std::string input);
void addToFile(const std::string& fileName, std::ios_base::openmode mode, const std::string& input);
bool validAccount(const std::string& fileName, std::string usernameToFind, std::string passwordToFind);
