#pragma once
#include "baseUser.h"
#include "cinema.h"
#include "city.h"
#include "cinema.h"

class User : BaseUser
{
public:
	void browseOffers();
	void browseCinemas(City city);

private:

};

extern User user;