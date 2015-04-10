/*************************************************************
Matthew Groeling

CS225 
Assignment 6
classBody.cpp

classBody.cpp defines all mediaItem class functions.
Each attribute has a get() and set() function to change their 
values from main.cpp.

clearInfo() 'zeroes' all attribute values
*************************************************************/

#include "classBody.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>

#define NAME_DEFAULT "Empty"
#define VALUE_DEFAULT 0.00
#define YEAR_DEFAULT 0
#define PRINT_DEFAULT false
#define EMPTY_DEFAULT true
#define AUTHOR_DEFAULT NULL
#define ELEMENT_DEFAULT 0
#define SEQUEL_DEFAULT NULL
#define PAGE_DEFAULT 0
#define GENRE_DEFAULT NONE
//int mediaItem::objectsAlive;
//setInfo can set all values for a mediaObject at once

//////////////////////////////////////////////////////////////////////////////////////
//addObject will increase the amount of objects created.
//
void objectAlive::addObject(){objectsAlive++;}

//////////////////////////////////////////////////////////////////////////////////////
//removeObject will decrease the amount of objects created.
//
void objectAlive::removeObject(){objectsAlive--;}

//////////////////////////////////////////////////////////////////////////////////////
//getAlive will return the amount of objects created.
//
int objectAlive::getAlive(){return objectsAlive;}

//////////////////////////////////////////////////////////////////////////////////////
//This is the media info default constructor which just assigns the private objects
//to global defaults set with the #defines.
//
mediaInfo::mediaInfo()
{
  itemName_ = NAME_DEFAULT;
  itemAuthor_ = AUTHOR_DEFAULT;
  itemPrint_ = PRINT_DEFAULT;
  itemYear_ = YEAR_DEFAULT;
  itemPageNum_ = PAGE_DEFAULT;
  itemValue_ = VALUE_DEFAULT;
  objectEmpty_ = EMPTY_DEFAULT;
  currentElement_ = ELEMENT_DEFAULT;
  sequelItem_ = SEQUEL_DEFAULT;
  itemGenre_ = GENRE_DEFAULT;
  objectAlive::addObject();
}//end of constructor

//////////////////////////////////////////////////////////////////////////////////////
//This is the mediaInfo class default destructor which will just decrease the amount
//of items created.
//
mediaInfo::~mediaInfo() //destructor - Decrements object counter
{
  objectAlive::removeObject();
}//end of destructor. 
  
///////////////////////////////////////////////////////////////////////////////////////////
//setGenre will take the object itemGenre from main and assign it to the itemGenre
//from the musicInfo private objects.
//
const char* GenreNames[] = 
  {
  stringify( Rock ),
  stringify( Country ),
  stringify( HipHop ),
  stringify( Techno ),
  stringify( Reggae ),
  stringify( Other )
  }; 
  
void mediaInfo::setGenre(std::string itemGenre)
{
	if(itemGenre == "Rock")
	{
		itemGenre_ = ROCK;
	}

	else if(itemGenre == "Country")
	{
		itemGenre_ = COUNTRY;
	}

	else if(itemGenre == "Techno")
	{
		itemGenre_ = TECHNO;
	}

	else if(itemGenre == "Reggae")
	{
		itemGenre_ = REGGAE;
	}

	else if(itemGenre == "HipHop")
	{
		itemGenre_ = HIPHOP;
	}
	else
	{
		itemGenre_ = OTHER;
		std::cout << "Item genre set to OTHER.\n";
	}
}//end of setGenre function. 

///////////////////////////////////////////////////////////////////////////////////////////
//These check functions will check what genre type the item value and return a boolean
//value.
//

bool mediaInfo::checkRock(bool &checkGenre)
  {
    if (itemGenre_ == ROCK)
      {
        checkGenre = true;
        return checkGenre;
      }
  };//end of checkRock
  
bool mediaInfo::checkCountry(bool &checkGenre)
  {
    if (itemGenre_ == COUNTRY)
      {
        checkGenre = true;
        return checkGenre;
      }
  };//end of checkCountry.
  
bool mediaInfo::checkHipHop(bool &checkGenre)
  {
    if (itemGenre_ == HIPHOP)
      {
        checkGenre = true;
        return checkGenre;
      }
  };//end of checkHipHop
  
bool mediaInfo::checkTechno(bool &checkGenre)
  {
    if (itemGenre_ == TECHNO)
      {
        checkGenre = true;
        return checkGenre;
      }
  };//end of checkTechno
  
bool mediaInfo::checkReggae(bool &checkGenre)
  {
    if (itemGenre_ == REGGAE)
      {
        checkGenre = true;
        return checkGenre;
      }
  };//end of checkReggae.
  
bool mediaInfo::checkOther(bool &checkGenre)
  {
    if (itemGenre_ == OTHER)
      {
        checkGenre = true;
        return checkGenre;
      }
  };//end of checkOther
//////////////////////////////////////////////////////////////////////////////////////
//getAuthor will print the author if it is not empty/default value.
//
void mediaInfo::getAuthor()
{

  if(itemAuthor_ != NULL)
  {
    std::cout << "  Author   : ";
    itemAuthor_->printName();
  }
  else
  {
    std::cout << "  No author set. Use T to set an author.\n";
  }
}//end of getAuthor

//////////////////////////////////////////////////////////////////////////////////////
//getSequel will print the sequel if it is not empty/default value.
//
int mediaInfo::getSequel()
{
  if(sequelItem_ != NULL)
  {
    std::cout << "  Sequel   : ";
    sequelItem_->printName();
  }
  else
  {
    std::cout << "  No sequel set.\n";
  }
}//end of getSequel

//////////////////////////////////////////////////////////////////////////////////////
//getType will return the type of sent item.
//
std::string mediaInfo::getType()
{return "*";}

//////////////////////////////////////////////////////////////////////////////////////
//setInfo will set the given objects of: itemName, itemValue, and itemYear, to private
//mediaInfo objects of: itemName_, itemValue_, and itemYear_.
//
void mediaInfo::setInfo(std::string itemName, float itemValue, int itemYear)
{
     itemName_ = itemName;
     itemValue_ = itemValue;
     itemYear_ = itemYear;
     objectEmpty_ = false; //set empty flag to false
}//end of setInfo.

//////////////////////////////////////////////////////////////////////////////////////
//setName will take the object itemName from main and assign it to the private object
//itemName_ from the mediaInfo class.
//
void mediaInfo::setName(std::string itemName)
{
     itemName_ = itemName;
     objectEmpty_ = false;
//     std::cout << "Item name set to: " << itemName_ << std::endl; //for script input debugging
}//end of setName.

//////////////////////////////////////////////////////////////////////////////////////
//setAuthor will take the object itemAuthor from main and assign it to the private object
//itemAuthor_ from the mediaInfo class.
//
void mediaInfo::setAuthor (Author* itemAuthor)
{
     itemAuthor_ = itemAuthor;
     objectEmpty_ = false;
//     std::cout << "Item author set to: " << std::endl;
     itemAuthor_->returnInfo(); //debugging
}//end of setAuthor.

//////////////////////////////////////////////////////////////////////////////////////
//setValue will take the object itemValue from main and assign it to the private object
//itemValue_ from the mediaInfo class.
//
void mediaInfo::setValue(float itemValue)
{
  itemValue_ = itemValue;
  objectEmpty_ = false;
//  std::cout << "Item value set to: " << itemValue_ << std::endl; //debugging
}//end of setValue.

//////////////////////////////////////////////////////////////////////////////////////
//setSequel will take the object sequelNum from main and assign it to the private object
//sequelItem_ from the mediaInfo class.
//
void mediaInfo::setSequel(mediaInfo* sequelNum)
{
  sequelItem_ = sequelNum;
  objectEmpty_ = false;
}//end setSequel function.

//////////////////////////////////////////////////////////////////////////////////////
//setYear will take the object itemYear from main and assign it to the private object
//itemYear_ from the mediaInfo class.
//
void mediaInfo::setYear(int itemYear)
{
  itemYear_ = itemYear;
  objectEmpty_ = false;
//  std::cout << "Item year set to: " << itemYear_ << std::endl; //debugging
}//end of setYear function.

//////////////////////////////////////////////////////////////////////////////////////
//setPage will take the object itemPageNum from main and assign it to the private object
//itemPageNum from the mediaInfo class.
//
void mediaInfo::setPage(int itemPageNum)
{
    itemPageNum_ = itemPageNum;
    objectEmpty_ = false;
//    std::cout << "Item pages set to: " << itemPageNum_ << std::endl; //debugging
}//end of setPage function.

//////////////////////////////////////////////////////////////////////////////////////
//setPrint will take the object itemPrint from main and assign it to the private object
//itemPrint_ from the mediaInfo class.
//
void mediaInfo::setPrint(bool itemPrint)
{
  itemPrint_ = itemPrint;
  objectEmpty_ = false;
//  std::cout << "Item print status set to: " << itemPrint_ << std::endl; //debugging
}

//////////////////////////////////////////////////////////////////////////////////////
//setElement will take the objects elementName, elementStart, and elementEnd, and assign
//them to the class members from the Element class.
//
void mediaInfo::setElement(std::string elementName, int elementStart, int elementEnd)
{
  elementObject[currentElement_].setName(elementName);
  elementObject[currentElement_].setStart(elementStart);
  elementObject[currentElement_].setEnd(elementEnd);
  currentElement_++;
}//end of setElement function.

//////////////////////////////////////////////////////////////////////////////////////
//printElement will print all elements of a specific mediaInfo object.
//
void mediaInfo::printElements()
{
  for(int count = 0; count < ELEMENTS; count++)
  {
    elementObject[count].printName();
    elementObject[count].printStart();
    elementObject[count].printEnd();
  }
}//end of printElements.

//////////////////////////////////////////////////////////////////////////////////////
//isEmpty will return the object objectEmpty_
bool mediaInfo::isEmpty()
{
  return objectEmpty_;
}

//////////////////////////////////////////////////////////////////////////////////////
//printName will print the mediaInfo name.
//
void mediaInfo::printName()
{
  std::cout << itemName_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////
//returnInfo will print the objects: itemName_, itemValue_, itemYear_, of specific
//object if they are empty/default values.
//
void mediaInfo::returnInfo()
{
  if(itemName_ != "Empty")
    {std::cout << "  Title    : " << itemName_ << std::endl;}
  if(itemValue_ != 0.00)
    {std::cout << "  Value    : " << itemValue_ << std::endl;}
  if(itemYear_ != 0)
    {std::cout << "  Year     : " << itemYear_ << std::endl;}
}

//////////////////////////////////////////////////////////////////////////////////////
//clearInfo will clear all objects of a specific object and set them to the default
//values. 
void mediaInfo::clearInfo()
   {
     itemName_ = "Empty";
     itemAuthor_ = NULL;
     itemYear_ = 0;
     itemValue_ = 0.00;
     sequelItem_ = NULL;
     objectEmpty_ = true;
   }