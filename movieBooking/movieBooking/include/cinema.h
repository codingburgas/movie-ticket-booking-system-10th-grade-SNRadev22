#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include "hall.h"
#include "movie.h"

class Cinema
{
public:
	std::string getName();
	std::string getCity();
	std::string getLocation();
	std::string getId();
	std::string getOwner();
	std::vector <Hall> getHalls();
	std::vector <Movie> getMovies();

	void setName(std::string newName);
	void setCity(std::string newCity);
	void setLocation(std::string newLocation);
	void setId(std::string newID);
	void setOwner(std::string newOwner);

	bool validCinema(const std::string& fileName, std::string idToFind, std::string nameToFind);
	void displayCinemas(std::vector<Cinema> cinemas);
	void addHall(Hall hall);
	Hall& findHall(std::string nameToFind);
	void addMovie(Movie movie);
	void loadHalls(const std::string& cinemaFileName, const std::string& hallFileName);
	void loadMovies(const std::string& cinemaFileName, const std::string& movieFileName);
	void dispalyMovies();
	void displayHalls();

private:
	std::string name;
	std::string city;
	std::string location;
	std::string id;
	std::string owner;
	std::vector<Hall> halls;
	std::vector<Movie> movies;
};

extern Cinema cinema;
