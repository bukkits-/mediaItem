/*************************************************************
Matthew Groeling

CS225 
Assignment 4
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
//int mediaItem::objectsAlive;
//setInfo can set all values for a mediaObject at once

void objectAlive::addObject(){objectsAlive++;}

void objectAlive::removeObject(){objectsAlive--;}

int objectAlive::getAlive(){return objectsAlive;}

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
  objectAlive::addObject();
}

mediaInfo::~mediaInfo() //destructor - Decrements object counter
{
  objectAlive::removeObject();
} 


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
}


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
}

std::string mediaInfo::getType()
{return "*";}

void mediaInfo::setInfo(std::string itemName, float itemValue, int itemYear)
{
     itemName_ = itemName;
     itemValue_ = itemValue;
     itemYear_ = itemYear;
     objectEmpty_ = false; //set empty flag to false
}

void mediaInfo::setName(std::string itemName)
{
     itemName_ = itemName;
     objectEmpty_ = false;
//     std::cout << "Item name set to: " << itemName_ << std::endl; //for script input debugging
}

void mediaInfo::setAuthor (Author* itemAuthor)
{
     itemAuthor_ = itemAuthor;
     objectEmpty_ = false;
//     std::cout << "Item author set to: " << std::endl;
     itemAuthor_->returnInfo(); //debugging
}

void mediaInfo::setValue(float itemValue)
{
  itemValue_ = itemValue;
  objectEmpty_ = false;
//  std::cout << "Item value set to: " << itemValue_ << std::endl; //debugging
}


void mediaInfo::setSequel(mediaInfo* sequelNum)
{
  sequelItem_ = sequelNum;
  objectEmpty_ = false;
}

void mediaInfo::setYear(int itemYear)
{
  itemYear_ = itemYear;
  objectEmpty_ = false;
//  std::cout << "Item year set to: " << itemYear_ << std::endl; //debugging
}

void mediaInfo::setPage(int itemPageNum)
{
    itemPageNum_ = itemPageNum;
    objectEmpty_ = false;
//    std::cout << "Item pages set to: " << itemPageNum_ << std::endl; //debugging
}

void mediaInfo::setPrint(bool itemPrint)
{
  itemPrint_ = itemPrint;
  objectEmpty_ = false;
//  std::cout << "Item print status set to: " << itemPrint_ << std::endl; //debugging
}

void mediaInfo::setElement(std::string elementName, int elementStart, int elementEnd)
{
  elementObject[currentElement_].setName(elementName);
  elementObject[currentElement_].setStart(elementStart);
  elementObject[currentElement_].setEnd(elementEnd);
  currentElement_++;
}

void mediaInfo::printElements()
{
  for(int count = 0; count < ELEMENTS; count++)
  {
    elementObject[count].printName();
    elementObject[count].printStart();
    elementObject[count].printEnd();
  }
}

bool mediaInfo::isEmpty()
{
  return objectEmpty_;
}

void mediaInfo::printName()
{
  std::cout << itemName_ << std::endl;
}

void mediaInfo::returnInfo()
{
  if(itemName_ != "Empty")
    {std::cout << "  Title    : " << itemName_ << std::endl;}
  if(itemValue_ != 0.00)
    {std::cout << "  Value    : " << itemValue_ << std::endl;}
  if(itemYear_ != 0)
    {std::cout << "  Year     : " << itemYear_ << std::endl;}
}

void mediaInfo::clearInfo()
   {
     itemName_ = "Empty";
     itemAuthor_ = NULL;
     itemYear_ = 0;
     itemValue_ = 0.00;
     sequelItem_ = NULL;
     objectEmpty_ = true;
   }