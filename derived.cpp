/*************************************************************
Matthew Groeling

CS225 
Assignment 6
derived.cpp

Implementation of derived class functions
*************************************************************/


#include <iostream>
#include <istream>
#include <string>
#include <fstream>

#include "derived.h"

#define GENRE_DEFAULT NONE
#define ISBN_DEFAULT "Empty"
#define MINUTES_DEFAULT 0.0
#define PRODUCER_DEFAULT "Empty"
#define DEF_ROCK 0
#define DEF_COUNTRY 1
#define DEF_HIPHOP 2
#define DEF_TECHNO 3
#define DEF_REGGAE 4
#define DEF_OTHER 5

/////////////////////////////////////////////////////////
// bookInfo functions

// bookInfo constructor
bookInfo::bookInfo()
{
	ISBN_ = ISBN_DEFAULT;
}//end of bookInfo class.

//////////////////////////////////////////////////////////////////////////////////////
//setISBN will take the object ISBN from main and assign it to the ISBN_ from the 
//bookInfo private objects.
//
void bookInfo::setISBN(std::string ISBN)
{
	ISBN_ = ISBN;
	objectEmpty_ = false;
};//end of setISBN function.


// Return functions
// Returns values of bookInfo class variables

///////////////////////////////////////////////////////////////////////////////////////////
//getISBN will return the object ISBN_ of the bookInfo class.
std::string bookInfo::getISBN()
{
	return ISBN_;
};//end of getISBN.

///////////////////////////////////////////////////////////////////////////////////////////
//
std::string bookInfo::getType()
{
	return "B";
}//end of getType function. 

// Print function
// Prints derived class specific information

///////////////////////////////////////////////////////////////////////////////////////////
//childPrintInfo function will print out the objects of bookInfo if they are empty.
//
void bookInfo::childPrintInfo()
{
	if(ISBN_ != ISBN_DEFAULT)
	{std::cout << "  ISBN: " << ISBN_ << std::endl;}
}//end of childPrintInfo function. 

//////////////////////////////////////////
// musicInfo functions

//Constructor

musicInfo::musicInfo()
{
	itemProducer_ = PRODUCER_DEFAULT;
	itemMinutes_ = MINUTES_DEFAULT;
	itemGenre_ = GENRE_DEFAULT;
}//end of musicInfo constructor.

//////////////////////////////////////////////////////////////////////////////////////
//setMinutes will take the object itemMinutes from main and assign it to the minutes_
//from the musicInfo private objects.
//
void musicInfo::setMinutes(float itemMinutes)
{
	itemMinutes_ = itemMinutes;
	objectEmpty_ = false;
}//end of setMinutes function. 

///////////////////////////////////////////////////////////////////////////////////////////
//getMinutes will return the object itemMinutes_ of the musicInfo class.
//
float musicInfo::getMinutes()
{
	return itemMinutes_;
}//end of getMinutes function.

///////////////////////////////////////////////////////////////////////////////////////////
//setDirector will take the object itemDirector from main and assign it to the itemDirector
//from the musicInfo private objects.
//
void musicInfo::setDirector(std::string itemDirector)
{
	itemProducer_ = itemDirector;
	objectEmpty_ = false;
}//end of setDirector function. 

///////////////////////////////////////////////////////////////////////////////////////////
//getDirector will return the object itemDirector_.
//
std::string musicInfo::getDirector()
{
	return itemProducer_;
}//end of getDirector function.

///////////////////////////////////////////////////////////////////////////////////////////
//
std::string musicInfo::getType()
{
	return "M";
}//end of getType function. 

///////////////////////////////////////////////////////////////////////////////////////////
//getGenre will return the object itemGenre_.
//
Genre musicInfo::getGenre()
{
	return itemGenre_;
}//end of getGenre function.

///////////////////////////////////////////////////////////////////////////////////////////
//childPrintInfo function will print out the objects of musicInfo if they are empty.
//
void musicInfo::childPrintInfo()
{
	if(itemMinutes_ != MINUTES_DEFAULT)
	{
		std::cout << "  Minutes: " << itemMinutes_ << std:: endl;
	}
	if(itemProducer_ != PRODUCER_DEFAULT)
	{
		std::cout << "  Producer: " << itemProducer_ << std::endl;
	}

}//end of childPrintInfo function. 

////////////////////////////////////////////////
// videoInfo functions

//constructor

videoInfo::videoInfo()
{
	itemDirector_ = PRODUCER_DEFAULT;
	itemMinutes_ = MINUTES_DEFAULT;
}//end of constructor.

// Set derived class specific values

///////////////////////////////////////////////////////////////////////////////////////////
//setDirector will take the object itemDirector from main and assign it to the itemDirector
//from the videoInfo private objects.
//
void videoInfo::setDirector(std::string itemDirector)
{
	itemDirector_ = itemDirector;
	objectEmpty_ = false;
}//end of setDirector.

///////////////////////////////////////////////////////////////////////////////////////////
//setMinutes will take the object itemMinutes from main and assign it to the itemMinutes_
//from the musicInfo private objects.
//
void videoInfo::setMinutes(float itemMinutes)
{
	itemMinutes_ = itemMinutes;
	objectEmpty_ = false;
}//end of setMinutes function.

// Return functions

///////////////////////////////////////////////////////////////////////////////////////////
//getDirector will return the object itemDirector_.
//
std::string videoInfo::getDirector()
{
	return itemDirector_;
}//end of getDirector function. 

///////////////////////////////////////////////////////////////////////////////////////////
//getMinutes will return the object itemMinutes_ of the videoInfo class. 
float videoInfo::getMinutes()
{
	return itemMinutes_;
}//end of getMinutes function. 

///////////////////////////////////////////////////////////////////////////////////////////
//
std::string videoInfo::getType()
{
	return "V";
}//end of getType.

///////////////////////////////////////////////////////////////////////////////////////////
//childPrintInfo function will print out the objects of musicInfo if they are empty.
//
void videoInfo::childPrintInfo()
{
	if(itemMinutes_ != MINUTES_DEFAULT)
	{
		std::cout << "  Minutes: " << itemMinutes_ << std::endl;
	}
	if(itemDirector_ != PRODUCER_DEFAULT)
	{
		std::cout << "  Director: " << itemDirector_ << std::endl;
	}
}

