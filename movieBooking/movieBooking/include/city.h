#pragma once
#include "cinema.h"
#include<string>
#include<vector>

class City
{
public:
	City findCity(std::string nameToFind);
	void addCinema(std::string cinemaId);
	void addCinemaToFile(const std::string fileName, std::string nameToFind, std::string cinemaId);

	std::string getName();
	std::vector<std::string> getCinemas();

	void setName(std::string newName);
	void setCinemas(std::vector<std::string> cinemasList);

private:
	std::string name;
	std::vector<std::string> cinemas;
};
extern std::vector<City> cities;