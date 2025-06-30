#pragma once
#include "baseUser.h"
#include "cinema.h"
#include "city.h"
#include "cinema.h"

class User : public BaseUser
{
public:
	User()
	{
		setEmail("");
		setUsername("");
		setPassword("");
		setRank("USER");
	}

	User(BaseUser& baseUser)
	{
		setEmail(baseUser.getEmail());
		setUsername(baseUser.getUsername());
		setPassword(baseUser.getPassword());
		setRank("USER");
	}

	void browseOffers();
	void browseCinemas(City& city);
	void browseMovies(Cinema cinema);
	void bookMovie(Movie& movie);

	void viewBookings();
	void searchMovies(std::vector<Cinema>& cinemas);

private:
	std::vector<Movie> bookings;
};

extern User user;