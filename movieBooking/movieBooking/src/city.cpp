#include "../include/city.h"

std::vector<City> cities;

City City::findCity(std::string nameToFind)
{
	for (size_t i = 0; i < cities.size(); ++i)
	{
		if (cities[i].name == nameToFind)
		{
			return cities[i];
		}
	}
}

void City::addCinema(std::string cinemaId)
{
	cinemas.push_back(cinemaId);
}

std::string City::getName()
{
	return name;
}

std::vector<std::string> City::getCinemas()
{
	return cinemas;
}

void City::setName(std::string newName)
{
	name = newName;
}

void City::setCinemas(std::vector<std::string> cinemasList)
{
	cinemas = cinemasList;
}