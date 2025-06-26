#include "../include/movie.h"

Movie movie;

std::string Movie::getTitle() 
{
	return title;
}
std::string Movie::getLanguage()
{
	return language;
}
std::string Movie::getGenre()
{
	return genre;
}
int Movie::getLength()
{
	return length;
}
std::string Movie::getDate()
{
	return date;
}
float Movie::getPrice()
{
	return price;
}
Hall Movie::getHall()
{
	return hall;
}

void Movie::setTitle(std::string newTitle)
{
	title = newTitle;
}
void Movie::setLanguage(std::string newLanguage)
{
	language = newLanguage;
}
void Movie::setGenre(std::string newGenre)
{
	genre = newGenre;
}
void Movie::setLength(int newLength)
{
	length = newLength;
}
void Movie::setDate(std::string newDate)
{
	date = newDate;
}
void Movie::setPrice(float newPrice)
{
	price = newPrice;
}
void Movie::setHall(Hall newHall)
{
	hall = newHall;
}