#pragma once
#include "baseUser.h"
#include "cinema.h"
#include "hall.h"
#include "Utility.h"
#include <iostream>
#include <vector>

class Manager : BaseUser
{
public:
	void addHalls();
	void addCinema();

private:
	std::vector<Cinema> ownedCinemas;
};

extern Manager manager;