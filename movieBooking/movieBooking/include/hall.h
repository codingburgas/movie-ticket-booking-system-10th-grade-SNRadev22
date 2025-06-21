#pragma once
#include<string>
#include<vector>

class Hall
{
public:
	std::string getName();
	std::string getLocation();

	void setName(std::string newName);
	void setLocation(std::string newLocation);

private:
	std::string name;
	std::string location;
	// seatLayout;
};

extern Hall hall;