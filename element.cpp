/*************************************************************
Matthew Groeling

CS225 
Assignment 3
element.cpp

element.cpp contains function implementation for the mediaElement class

*************************************************************/


#include "element.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>

void mediaElement::setName(std::string elementName)
{
  elementName_ = elementName;
}

void mediaElement::setStart(int elementStart)
{
	elementStart_ = elementStart;
}

void mediaElement::setEnd(int elementEnd)
{
	elementEnd_ = elementEnd;
}

void mediaElement::printName()
{
if(elementName_ != "Empty")
    {std::cout << "  Element Name: " << elementName_ << std::endl;}
}

void mediaElement::printStart()
{
if(elementStart_ != 0)
    {std::cout << "  Start: " << elementStart_ << std::endl;}
}

void mediaElement::printEnd()
{
if(elementEnd_ != 0)
    {std::cout << "  End: " << elementEnd_ << std::endl;}
}