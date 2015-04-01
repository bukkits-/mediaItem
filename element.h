/*************************************************************
Matthew Groeling

CS225 
Assignment 3
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
  std::string m_elementName;
  int m_elementStart;
  int m_elementEnd;
  
 public:
   //constructor - sets all attributes to initial values and increments object counter
   mediaElement(std::string elementName = "Empty", int elementStart = 0, int elementEnd = 0)
   {
    m_elementName = elementName;
    m_elementStart = elementStart;
    m_elementEnd = elementEnd;
    //mediaInfo::objectsAlive++;
   }
   ~mediaElement()
   {
    //mediaInfo::objectsAlive--;
   }
   void setName(std::string elementName);

   void setStart(int elementStart);

   void setEnd(int elementEnd);

   void printName();

   void printStart();

   void printEnd();
};

#endif