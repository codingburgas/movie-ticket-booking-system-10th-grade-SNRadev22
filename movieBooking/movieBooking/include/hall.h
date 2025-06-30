#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<sstream>

class Hall
{
public:
	std::string getId();
	std::string getName();
	std::string getLocation();
	int getNumberOfSeats();
	int getRows();

	void setId(std::string newId);
	void setName(std::string newName);
	void setLocation(std::string newLocation);
	void setNumberOfSeats(int seats);
	void setRows(int newRows);
	void setSeatLayout(std::vector<std::string> newLayout);
	void editSeatLayout(int row, int seat);
	void saveToFile(const std::string& filename);

	void displayLayout();
	void setLayout();

private:
	std::string id;
	std::string name;
	std::string location;
	int numberOfSeats;
	std::vector<std::string> seatLayout;
	int rows;
};

extern Hall hall;