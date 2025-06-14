#pragma once
#include<string>
#include<vector>

class Cinema
{
public:
	std::string getName();
	std::string getCity();
	std::string getLocation();
	std::string getId();

	void setName(std::string newName);
	void setCity(std::string newCity);
	void setLocation(std::string newLocation);
	void setId(std::string newID);

private:
	std::string name;
	std::string city;
	std::string location;
	std::string id;
};

extern Cinema cinema;
