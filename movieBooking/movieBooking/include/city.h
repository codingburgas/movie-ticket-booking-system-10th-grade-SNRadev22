#pragma once
#include "cinema.h"
#include<string>
#include<vector>

class City
{
public:
	City findCity(std::string nameToFind);
	void addCinema(Cinema cinema);
	void addCinemaToFile(const std::string fileName, std::string nameToFind, std::string cinemaId);
	void loadCities(const std::string fileName);

	std::string getName();
	std::vector<Cinema> getCinemas();

	void setName(std::string newName);
	void setCinemas(std::vector<Cinema> cinemasList);

private:
	std::string name;
	std::vector<Cinema> cinemas;
};
extern std::vector<City> cities;