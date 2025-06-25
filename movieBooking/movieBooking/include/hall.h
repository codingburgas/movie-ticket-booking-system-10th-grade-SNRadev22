#pragma once
#include<string>
#include<vector>

class Hall
{
public:
	std::string getName();
	std::string getLocation();
	int getNumberOfSeats();

	void setName(std::string newName);
	void setLocation(std::string newLocation);
	void setNumberOfSeats(int seats);

private:
	std::string name;
	std::string location;
	int numberOfSeats;
};

extern Hall hall;