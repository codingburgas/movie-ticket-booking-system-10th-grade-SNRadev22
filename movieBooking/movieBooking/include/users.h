#pragma once
#include<string>
#include <ios>
enum rank { USER, ADMIN, MANAGER };
class User
{
public:
	std::string getEmail();
	std::string getUsername();
	std::string getPassword();
	rank getRank();

	void setEmail(std::string newEmail);
	void setUsername(std::string newUsername);
	void setPassword(std::string newPassword);
	void setRank(std::string rankStr);

	bool validAccount(const std::string& fileName, std::string usernameToFind, std::string passwordToFind);

private:
	std::string email;
	std::string username;
	std::string password;
	rank userRank;
};

extern User user;
