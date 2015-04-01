#include <iostream>
#include <istream>
#include <string>
#include <fstream>

#include "derived.h"

#define GENRE_DEFAULT NONE
#define ISBN_DEFAULT "Empty"
#define MINUTES_DEFAULT 0.0
#define PRODUCER_DEFAULT "Empty"

/////////////////////////////////////////////////////////
// bookInfo functions

// bookInfo constructor
bookInfo::bookInfo()
{
	ISBN_ = ISBN_DEFAULT;
}

void bookInfo::setISBN(std::string ISBN)
{
	ISBN_ = ISBN;
	objectEmpty_ = false;
};


// Return functions
// Returns values of bookInfo class variables

std::string bookInfo::getISBN()
{
	return ISBN_;
};

std::string bookInfo::getType()
{
	return "B";
}

// Print function
// Prints derived class specific information

void bookInfo::childPrintInfo()
{
	if(ISBN_ != ISBN_DEFAULT)
	{std::cout << "  ISBN: " << ISBN_ << std::endl;}
}

//////////////////////////////////////////
// musicInfo functions

//Constructor

musicInfo::musicInfo()
{
	itemProducer_ = PRODUCER_DEFAULT;
	itemMinutes_ = MINUTES_DEFAULT;
	itemGenre_ = GENRE_DEFAULT;
}
void musicInfo::setMinutes(float itemMinutes)
{
	itemMinutes_ = itemMinutes;
	objectEmpty_ = false;
}

float musicInfo::getMinutes()
{
	return itemMinutes_;
}

void musicInfo::setDirector(std::string itemDirector)
{
	itemProducer_ = itemDirector;
	objectEmpty_ = false;
}

std::string musicInfo::getDirector()
{
	return itemProducer_;
}

std::string musicInfo::getType()
{
	return "M";
}

void musicInfo::setGenre(std::string itemGenre)
{
	if(itemGenre == "Rock")
	{
		itemGenre_ = ROCK;
	}

	if(itemGenre == "Country/Western")
	{
		itemGenre_ = COUNTRY;
	}

	if(itemGenre == "Techno")
	{
		itemGenre_ = TECHNO;
	}

	if(itemGenre == "Reggae")
	{
		itemGenre_ = REGGAE;
	}

	if(itemGenre == "HipHop")
	{
		itemGenre_ = HIPHOP;
	}
	else
	{
		itemGenre_ = OTHER;
		std::cout << "Item genre set to OTHER.\n";
	}
}

Genre musicInfo::getGenre()
{
	return itemGenre_;
}

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

}

////////////////////////////////////////////////
// videoInfo functions

//constructor

videoInfo::videoInfo()
{
	itemDirector_ = PRODUCER_DEFAULT;
	itemMinutes_ = MINUTES_DEFAULT;
}

// Set derived class specific values

void videoInfo::setDirector(std::string itemDirector)
{
	itemDirector_ = itemDirector;
	objectEmpty_ = false;
}

void videoInfo::setMinutes(float itemMinutes)
{
	itemMinutes_ = itemMinutes;
	objectEmpty_ = false;
}

// Return functions

std::string videoInfo::getDirector()
{
	return itemDirector_;
}

float videoInfo::getMinutes()
{
	return itemMinutes_;
}

std::string videoInfo::getType()
{
	return "V";
}

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

