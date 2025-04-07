#pragma once
#include<string>

struct User
{
	std::string email;
	std::string username;
	std::string password;
	enum rank {USER, ADMIN, MANAGER};
};
