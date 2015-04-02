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


//////////////////////////////////////////////////////////////////////////////////////
//setName function will take the input elementName from main, and assign it to the
//private variable of elementName_ from the element class.
//
void mediaElement::setName(std::string elementName)
{
  elementName_ = elementName;
}//End of Element setName function.

//////////////////////////////////////////////////////////////////////////////////////
//setStart function will take the input elementStart from main, and assign it to the
//private variable of elementStart_ from the element class.
//
void mediaElement::setStart(int elementStart)
{
	elementStart_ = elementStart;
}//end of Element setStart.

//////////////////////////////////////////////////////////////////////////////////////
//setEnd function will take the input elementEnd from main, and assign it to the
//private variable of elementEnd_ from the element class.
//
void mediaElement::setEnd(int elementEnd)
{
	elementEnd_ = elementEnd;
}//end of Element setEnd function.

//////////////////////////////////////////////////////////////////////////////////////
//printName function when called will print the elementName variable from the element
//class.
//
void mediaElement::printName()
{
if(elementName_ != "Empty")
    {std::cout << "  Element Name: " << elementName_ << std::endl;}
}//end of Element printName function.

/////////////////////////////////////////////////////////////////////////////////////////
//printStart function when called will print the elementStart_ variable from the element
//class.
//
void mediaElement::printStart()
{
if(elementStart_ != 0)
    {std::cout << "  Start: " << elementStart_ << std::endl;}
}//end of Element printStart function.

/////////////////////////////////////////////////////////////////////////////////////////
//printEnd function when called will print the elementEnd_ variable from the element
//class.
//
void mediaElement::printEnd()
{
if(elementEnd_ != 0)
    {std::cout << "  End: " << elementEnd_ << std::endl;}
}//end of Element printEnd() function.
