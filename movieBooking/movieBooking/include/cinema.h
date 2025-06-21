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
	std::string getOwner();

	void setName(std::string newName);
	void setCity(std::string newCity);
	void setLocation(std::string newLocation);
	void setId(std::string newID);
	void setOwner(std::string newOwner);

private:
	std::string name;
	std::string city;
	std::string location;
	std::string id;
	std::string owner;
};

extern Cinema cinema;
