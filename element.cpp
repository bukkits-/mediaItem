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
  m_elementName = elementName;
}

void mediaElement::setStart(int elementStart)
{
	m_elementStart = elementStart;
}

void mediaElement::setEnd(int elementEnd)
{
	m_elementEnd = elementEnd;
}

void mediaElement::printName()
{
if(m_elementName != "Empty")
    {std::cout << "  Element Name: " << m_elementName << std::endl;}
}

void mediaElement::printStart()
{
if(m_elementStart != 0)
    {std::cout << "  Start: " << m_elementStart << std::endl;}
}

void mediaElement::printEnd()
{
if(m_elementEnd != 0)
    {std::cout << "  End: " << m_elementEnd << std::endl;}
}