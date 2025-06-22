#pragma once
#include "baseUser.h"
#include "cinema.h"

class User : BaseUser
{
public:
	void browseOffers();

private:
	std::vector<Cinema> ownedCinemas;
};

extern User manager;