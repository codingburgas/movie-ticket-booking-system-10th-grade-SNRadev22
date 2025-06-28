#include "../include/city.h"
#include <sstream>

std::vector<City> cities;

Cinema City::findCinema(std::string nameToFind)
{
	for (size_t i = 0; i < cinemas.size(); i++)
	{
		if (cinemas[i].getName() == nameToFind)
		{
			return cinemas[i];
		}
	}
	std::cerr << "Cinema not found!" << std::endl;
	return Cinema();
}

void City::loadCities(const std::string fileName)
{
    std::ifstream cityFile(fileName);
    if (!cityFile.is_open())
    {
        std::cerr << "Error while opening file: " << fileName << std::endl;
        return;
    }

    std::string cityName;
    while (getline(cityFile, cityName))
    {
        City currentCity;
        currentCity.setName(cityName);

        std::string line;
        if (getline(cityFile, line))  // line with cinema IDs
        {
            std::istringstream iss(line);
            std::string idToFind;

            while (iss >> idToFind)
            {
                std::ifstream cinemaFile("assets/cinemas.txt");
                if (!cinemaFile.is_open())
                {
                    std::cerr << "Error while opening file: assets/cinemas.txt" << std::endl;
                    continue;
                }

                std::string id, skip, name, city, location, owner;
                while (getline(cinemaFile, id))
                {
                    getline(cinemaFile, skip);
                    getline(cinemaFile, skip);
                    getline(cinemaFile, name);
                    getline(cinemaFile, city);
                    getline(cinemaFile, location);
                    getline(cinemaFile, owner);

                    if (id == idToFind)
                    {
                        Cinema cinema;
                        cinema.setId(id);
                        cinema.setName(name);
                        cinema.setCity(city);
                        cinema.setLocation(location);
                        cinema.setOwner(owner);
                        cinema.loadHalls("assets/cinemas.txt", "assets/halls.txt");
                        cinema.loadMovies("assets/cinemas.txt", "assets/movies.txt");

                        currentCity.addCinema(cinema);
                        break;
                    }
                }

                cinemaFile.close();
            }
        }

        cities.push_back(currentCity);
    }

    cityFile.close();
}


void City::addCinema(Cinema cinema)
{
	cinemas.push_back(cinema);
}

std::string City::getName()
{
	return name;
}

std::vector<Cinema> City::getCinemas()
{
	return cinemas;
}

void City::setName(std::string newName)
{
	name = newName;
}

void City::setCinemas(std::vector<Cinema> cinemasList)
{
	cinemas = cinemasList;
}