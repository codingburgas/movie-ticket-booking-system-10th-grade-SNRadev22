#pragma once
#include "managerFunctions.h"
#include "cinema.h"
#include "city.h"

class Admin : public Manager
{
public:
	Admin()
	{
		setEmail("");
		setUsername("");
		setPassword("");
		setRank("ADMIN");
	}
	Admin(BaseUser& user) {
		setEmail(user.getEmail());
		setUsername(user.getUsername());
		setPassword(user.getPassword());
		setRank("ADMIN");
	}

	Cinema& getCinema();

	void setCinema(Cinema cinema);

	Cinema& findWorkingCinema(std::string idToFind);
	void loadWorkingCinema(const std::string& fileName, const std::string& emailToFind);

private:
	Cinema workingCinema;
};

extern Admin admin;