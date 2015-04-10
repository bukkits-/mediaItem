/*************************************************************
Matthew Groeling
Joe Mehltretter
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

//////////////////////////////////////////////////////////////////////////////////////
//addAuthor will increase the amount of authors created.
//
void objectAuthorAlive::addAuthor(){authorsAlive++;}

//////////////////////////////////////////////////////////////////////////////////////
//removed will decrease the amount of authors created.
//
void objectAuthorAlive::removeAuthor(){authorsAlive--;}

//////////////////////////////////////////////////////////////////////////////////////
//getAuthorAlive will return the amount of authors created.
//
int objectAuthorAlive::getAuthorAlive(){return authorsAlive;}

//////////////////////////////////////////////////////////////////////////////////////
//setName function will take the input authorName from main, and assign it to the
//private variable of authorName_ from the author class.
//
void Author::setName(std::string authorName)
{
	authorName_ = authorName;
	authorActive_ = true;
}

//////////////////////////////////////////////////////////////////////////////////////
//setBorn function will take the input yearBorn from main, and assign it to the
//private variable of yearBorn_ from the element class.
//
void Author::setBorn(int yearBorn)
{
	yearBorn_ = yearBorn;
	authorActive_ = true;
}

//////////////////////////////////////////////////////////////////////////////////////
//setDied function will take the input yearDied from main, and assign it to the
//private variable of yearDied_ from the element class.
//
void Author::setDied(int yearDied) 
{
	yearDied_ = yearDied;
	authorActive_ = true;
}

//////////////////////////////////////////////////////////////////////////////////////
//The returnInfo function when called will print the author Class variables.
//
void Author::returnInfo()
{
	if(authorName_ != "Empty")
		{std::cout << "  Name: " << authorName_ << std::endl;}
	if(yearBorn_ != 0)
		{std::cout << "  Born: " << yearBorn_ << std::endl;}
	if(yearDied_ != 0)
		{std::cout << "  Died: " << yearDied_ << std::endl;}
}

//////////////////////////////////////////////////////////////////////////////////////
//printName function when called will print the authorName_ variable from the author
//class.
//
void Author::printName()
{
	if(authorName_ != "Empty")
		{std::cout << authorName_ << std::endl;}
}

//////////////////////////////////////////////////////////////////////////////////////
//isActive will return whether or not the author was assigned.
//
bool Author::isActive()
{
	return authorActive_;
}