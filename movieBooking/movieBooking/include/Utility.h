#pragma once
#include "baseUser.h"
#include<iostream>
#include<fstream>

void drawHomePage();
std::string getUserInput();
bool exists(const std::string fileName, std::string input);
void addToFile(const std::string& fileName, std::ios_base::openmode mode, const std::string& input);
void addFragmentToFile(const std::string fileName, std::string toFind, std::string toAdd);