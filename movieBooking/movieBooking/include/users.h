#pragma once
#include<string>
#include <ios>

struct User
{
	std::string email;
	std::string username;
	std::string password;
	enum rank {USER, ADMIN, MANAGER};
};

extern User user;

void addToFile(std::fstream& file, const std::string& fileName, std::ios_base::openmode mode, std::string& input);
