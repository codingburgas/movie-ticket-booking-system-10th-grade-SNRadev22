#pragma once
#include "baseUser.h"
#include "cinema.h"
#include "city.h"
#include "cinema.h"

class User : public BaseUser
{
public:
	void browseOffers();
	void browseCinemas(City city);
	void browseMovies(Cinema cinema);

private:

};

extern User user;