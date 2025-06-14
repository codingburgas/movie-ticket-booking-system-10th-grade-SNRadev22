#pragma once
#include "users.h"
#include<iostream>
#include<fstream>

void drawHomePage();
std::string getUserInput();
bool exists(const std::string fileName, std::string input);
void addToFile(const std::string& fileName, std::ios_base::openmode mode, const std::string& input);