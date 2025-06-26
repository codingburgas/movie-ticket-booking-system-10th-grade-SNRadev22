#pragma once
#include<string>
#include<vector>
#include "hall.h"

class Movie
{
public:
	std::string getTitle();
	std::string getLanguage();
	std::string getGenre();
	int getLength();
	std::string getDate();
	float getPrice();
	Hall getHall();

	void setTitle(std::string title);
	void setLanguage(std::string language);
	void setGenre(std::string genre);
	void setLength(int length);
	void setDate(std::string date);
	void setPrice(float price);
	void setHall(Hall hall);

private:
	std::string title;
	int length;
	std::string language;
	std::string genre;
	std::string date;
	float price;
	Hall hall;
};

extern Movie movie;