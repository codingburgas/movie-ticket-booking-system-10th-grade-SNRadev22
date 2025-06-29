#pragma once
#include<string>
#include<vector>

class Hall
{
public:
	std::string getId();
	std::string getName();
	std::string getLocation();
	int getNumberOfSeats();

	void setId(std::string newId);
	void setName(std::string newName);
	void setLocation(std::string newLocation);
	void setNumberOfSeats(int seats);

private:
	std::string id;
	std::string name;
	std::string location;
	int numberOfSeats;
};

extern Hall hall;