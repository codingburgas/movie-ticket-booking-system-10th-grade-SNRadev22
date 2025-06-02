#include "../include/Utility.h"

void setRank(std::string rankStr)
{
	if (rankStr == "USER")
	{
		user.userRank = User::USER;
		std::cout << "User" << std::endl;
	}
	else if (rankStr == "ADMIN")
	{
		user.userRank = User::ADMIN;
		std::cout << "Admin" << std::endl;
	}
	else if (rankStr == "MANAGER")
	{
		user.userRank = User::MANAGER;
		std::cout << "Manager" << std::endl;
	}
}