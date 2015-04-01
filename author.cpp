/*************************************************************
Matthew Groeling

CS225 
Assignment 6
classBody.cpp

author.cpp contains implementation of the author class.
This includes functions to set the author's name, birth, death
and to return values.
*************************************************************/

#include "author.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>

void objectAuthorAlive::addAuthor(){authorsAlive++;}

void objectAuthorAlive::removeAuthor(){authorsAlive--;}

int objectAuthorAlive::getAuthorAlive(){return authorsAlive;}

void Author::setName(std::string authorName)
{
	authorName_ = authorName;
	authorActive_ = true;
}

void Author::setBorn(int yearBorn)
{
	yearBorn_ = yearBorn;
	authorActive_ = true;
}

void Author::setDied(int yearDied) 
{
	yearDied_ = yearDied;
	authorActive_ = true;
}

void Author::returnInfo()
{
	if(authorName_ != "Empty")
		{std::cout << "  Name: " << authorName_ << std::endl;}
	if(yearBorn_ != 0)
		{std::cout << "  Born: " << yearBorn_ << std::endl;}
	if(yearDied_ != 0)
		{std::cout << "  Died: " << yearDied_ << std::endl;}
}

void Author::printName()
{
	if(authorName_ != "Empty")
		{std::cout << authorName_ << std::endl;}
}

bool Author::isActive()
{
	return authorActive_;
}