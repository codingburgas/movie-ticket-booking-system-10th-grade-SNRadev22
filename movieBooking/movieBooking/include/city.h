#pragma once
#include "cinema.h"
#include<string>
#include<vector>

struct City
{
	std::string name;
	std::string location;
	std::vector<Cinema> cinemas;
};
