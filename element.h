/*************************************************************
Matthew Groeling
Joe Mehltretter
CS225 
Assignment 6
element.h

element.h contains constructor and destructor for the mediaElement class

*************************************************************/

#include <iostream>
#include <istream>
#include <string>
#include <fstream>

#ifndef ELEMENT_H
#define ELEMENT_H

class mediaElement
{
  private:

    std::string elementName_;
    int elementStart_;
    int elementEnd_;
  
 public:
   //constructor - sets all attributes to initial values and increments object counter
   mediaElement(std::string elementName = "Empty", int elementStart = 0, int elementEnd = 0)
   {
    elementName_ = elementName;
    elementStart_ = elementStart;
    elementEnd_ = elementEnd;
    //mediaInfo::objectsAlive++;
   }
   ~mediaElement()
   {
    //mediaInfo::objectsAlive--;
   }

    template <class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
      ar & elementName_;
      ar & elementStart_;
      ar & elementEnd_;  
    } 

   void setName(std::string elementName);

   void setStart(int elementStart);

   void setEnd(int elementEnd);

   void printName();

   void printStart();

   void printEnd();
};

#endif