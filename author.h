/*************************************************************
Matthew Groeling

CS225 
Assignment 6
classBody.cpp

author.h contains the Author class constructor and destructor.
*************************************************************/

#include <iostream>
#include <istream>
#include <string>
#include <fstream>

#ifndef AUTHOR_H
#define AUTHOR_H

namespace objectAuthorAlive
{
  static int authorsAlive = 0;

  void addAuthor();
  void removeAuthor();
  int getAuthorAlive();
}

class Author
{
  std::string authorName_;
  int yearBorn_;
  int yearDied_;
  bool authorActive_;
  
 public:
   //constructor - sets all attributes to initial values and increments object counter
   Author(std::string authorName="Empty", int yearBorn = 0, int yearDied = 0, bool authorActive = false)
   {
    authorName_ = authorName;
    yearBorn_ = yearBorn;
    yearDied_ = yearDied;
    authorActive_ = authorActive;
    objectAuthorAlive::addAuthor();    
   }

   ~Author()
   {
    objectAuthorAlive::removeAuthor();
   }

   void setName(std::string authorName);

   void setBorn(int yearBorn);

   void setDied(int yearDied);

   void returnInfo();

   bool isActive();

   void printName();
};

#endif