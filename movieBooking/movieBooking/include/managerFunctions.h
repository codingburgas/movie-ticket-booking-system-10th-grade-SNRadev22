#pragma once
#include "baseUser.h"
#include "cinema.h"
#include "hall.h"
#include "Utility.h"
#include <iostream>
#include <vector>
#include "movie.h"

class Manager : public BaseUser
{
public:
	Manager()
	{
		setEmail("");
		setUsername("");
		setPassword("");
		setRank("MANAGER");
	}

	Manager(BaseUser& user) {
		setEmail(user.getEmail());
		setUsername(user.getUsername());
		setPassword(user.getPassword());
		setRank("MANAGER");
	}
	
	void addHalls();
	void addCinema();
	void displayCinemas();
	void addMovie();
	Cinema& findCinema(std::string nameToFind);
	void loadOwnedCinemas(const std::string fileName, std::string managerEmailToFInd);

	void editMovie();

private:
	std::vector<Cinema> ownedCinemas;
};

extern Manager manager;