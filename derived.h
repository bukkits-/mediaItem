/********************************************
Matthew Groeling
Joe Mehltretter
CS225
Assignment 6
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
	
	virtual int rank() {return 200;};
	
	void writeData(std::ofstream & _fstream);

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

	friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
  	ar & boost::serialization::base_object<mediaInfo>(*this);
  	ar & itemMinutes_;
  	ar & itemProducer_;
  	ar & itemGenre_;
  } 

public:
	
	musicInfo();

	~musicInfo(){};
	
	virtual int rank() {return 300;};
	
	void writeData(std::ofstream & _fstream);

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

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
  	ar & boost::serialization::base_object<mediaInfo>(*this);
  	ar & itemMinutes_;
  	ar & itemDirector_;
  } 

public:
	videoInfo();

	~videoInfo(){};
	
	void writeData(std::ofstream & _fstream);
	
	virtual int rank() {return 400;};

	void setDirector(std::string itemDirector);

	std::string getDirector();

	void setMinutes(float itemMinutes);

	std::string getType();

	float getMinutes();

	void childPrintInfo();
};
#endif