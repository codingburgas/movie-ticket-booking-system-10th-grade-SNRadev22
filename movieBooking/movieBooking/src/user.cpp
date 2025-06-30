#include "../include/user.h"
#include <vector>
#include "../include/Utility.h"

User user;
City currentCity;

void User::browseOffers()
{
	std::fstream file;
	std::string city;

	file.open("assets/cities.txt");
	if (!file.is_open())
	{
		std::cerr << "Error while opening file!" << std::endl;
	}
	else
	{
		while (getline(file, city))
		{
			std::cout << city << std::endl;
			getline(file, city);
		}

		std::string chosenCityName;
		std::cin.ignore();
		while (true)
		{
			chosenCityName = getUserInput();
			if (exists("assets/cities.txt", chosenCityName))
			{
				City& currentCity = findCity(chosenCityName);
				browseCinemas(currentCity);
				file.close();
				break;
			}
			else
			{
				std::cout << "There are no cinemas in this city!" << std::endl;
			}
		}
	}
}

void User::browseCinemas(City& city)
{
		cinema.displayCinemas(city.getCinemas());

		std::string chosenCinema;
		while (true)
		{
			chosenCinema = getUserInput();
			if (exists("assets/cinemas.txt", chosenCinema))
			{
				Cinema cinema = city.findCinema(chosenCinema);
				browseMovies(cinema);
				break;
			}
			else
			{
				std::cout << "There are no cinemas with this name!" << std::endl;
			}
		}
	}

void User::browseMovies(Cinema cinema)
{
	std::cout << "---MOVIES---" << std::endl;
	cinema.dispalyMovies();

	std::string chosenMovie;
	while (true)
	{
		chosenMovie = getUserInput();
		if (exists("assets/movies.txt", chosenMovie))
		{
			Movie& movie = cinema.findMovie(chosenMovie);
			bookMovie(movie);

			bookings.push_back(movie);
			addFragmentToFile("assets/accounts.txt", this->getEmail(), movie.getId(), 1);
			std::cout << "You have selected the movie: " << chosenMovie << std::endl;
			break;
		}
		else
		{
			std::cout << "There are no movies with this title!" << std::endl;
		}
	}
}

void User::bookMovie(Movie& movie)
{
	Hall& hall = movie.getHall();
	hall.displayLayout();

	std::cout << "Enter the row number you want to book: ";
	int row;
	std::cin >> row;
	std::cin.ignore();

	std::cout << "Enter the seat number you want to book: ";
	int seat;
	std::cin >> seat;
	std::cin.ignore();

	hall.editSeatLayout(row, seat);
	hall.saveToFile("assets/halls.txt");
}

void User::viewBookings()
{
	if (bookings.empty())
	{
		std::cout << "You have no bookings." << std::endl;
		return;
	}
	std::cout << "Your bookings:" << std::endl;
	for (Movie& movie : bookings)
	{
		std::cout << std::endl << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Movie Title: " << movie.getTitle() << std::endl;
		std::cout << "Date: " << movie.getDate() << std::endl;
		std::cout << "Price: $" << movie.getPrice() << std::endl;
		std::cout << "Hall: " << movie.getHall().getName() << std::endl;
		std::cout << "------------------------" << std::endl;
	}
}

void User::searchMovies(std::vector<Cinema>& cinemas)
{
	std::cout << "---SEARCH MOVIES---\n";
	std::cout << "Search by:\n1. Title\n2. Language\n3. Genre\n4. Release Date\nYour choice: ";
	int choice;
	std::cin >> choice;
	std::cin.ignore();

	std::string query;
	std::cout << "Enter your search query: ";
	std::getline(std::cin, query);

	bool found = false;

	for (Cinema& cinema : cinemas)
	{
		for (Movie& movie : cinema.getMovies())
		{
			bool match = false;

			switch (choice)
			{
			case 1:
				match = (movie.getTitle() == query);
				break;
			case 2:
				match = (movie.getLanguage() == query);
				break;
			case 3:
				match = (movie.getGenre() == query);
				break;
			case 4:
				match = (movie.getDate() == query);
				break;
			default:
				std::cerr << "Invalid choice.\n";
				return;
			}

			if (match)
			{
				std::cout << "\nTitle: " << movie.getTitle()
					<< "\nLanguage: " << movie.getLanguage()
					<< "\nGenre: " << movie.getGenre()
					<< "\nDate: " << movie.getDate()
					<< "\nPrice: $" << movie.getPrice()
					<< "\nHall: " << movie.getHall().getName()
					<< "\nCinema: " << cinema.getName()
					<< "\n---------------------------\n";
				found = true;
			}
		}
	}

	if (!found)
	{
		std::cout << "No movies found matching your criteria.\n";
	}
}