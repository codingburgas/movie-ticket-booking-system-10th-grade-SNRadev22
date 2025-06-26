#pragma once
#include "baseUser.h"
#include "cinema.h"
#include "hall.h"
#include "Utility.h"
#include <iostream>
#include <vector>
#include "movie.h"

class Manager : BaseUser
{
public:
	void addHalls();
	void addCinema();
	void loadCinemas(const std::string& fileName);
	void displayCinemas();
	void addMovie();
	Cinema findCinema(std::string nameToFind);

private:
	std::vector<Cinema> ownedCinemas;
};

extern Manager manager;