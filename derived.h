/********************************************
Matthew Groeling

CS225
Assignment 4
classBody.h

The classes derived from mediaInfo live here 

*********************************************/

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "classBody.h"

#ifndef _DERIVED_H
#define _DERIVED_H

class bookInfo : public mediaInfo
{

private:
	std::string ISBN_;

public:
	bookInfo();

	~bookInfo(){};
	
	virtual int rank() {return 100;};

	void setISBN(std::string ISBN);

	std::string getISBN();

	std::string getType();

	void childPrintInfo();
};


class musicInfo : public mediaInfo
{
private:
	float itemMinutes_;
	std::string itemProducer_;
	Genre itemGenre_;

public:
	
	musicInfo();

	~musicInfo(){};
	
	virtual int rank() {return 200;};

	void setMinutes(float itemMinutes);

	void setDirector(std::string itemDirector);

	void setGenre(std::string itemGenre);

	float getMinutes();

	Genre getGenre();

	std::string getDirector();

	std::string getType();

	void childPrintInfo();

};

class videoInfo : public mediaInfo
{
private:
	float itemMinutes_;
	std::string itemDirector_;

public:
	videoInfo();

	~videoInfo(){};
	
	virtual int rank() {return 300;};

	void setDirector(std::string itemDirector);

	std::string getDirector();

	void setMinutes(float itemMinutes);

	std::string getType();

	float getMinutes();

	void childPrintInfo();
};
#endif