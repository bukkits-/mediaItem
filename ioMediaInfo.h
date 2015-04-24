/********************************************
Matthew Groeling
Joe Mehltretter
CS225
Assignment 6
classBody.h

mediaInfo is a base class, used primarily
for other classes to inherit from.

classBody.h holds the mediaInfo class and it's
constructor and destructor. 

*********************************************/

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "classBody.h"

#ifndef IOMEDIAINFO_H
#define IOMEDIAINFO_H
#define MAX_STRING_SIZE 50

class ioMediaInfo
 {
   private:
 
     std::string mediaItemName_;
     int mediaItemYear_; 
     int mediaItemPageNum_;
     bool mediaItemPrint_;
     float mediaItemValue_;
     int mediaItemAuthor_; //used to associate an author
  
  public:
  
     ioMediaInfo();
     
     ~ioMediaInfo();
     
     void assignVariables(std::ofstream & _fstream, mediaInfo*);
     
     //writeToFile();
  
     //readToFile();
     
 };//end of class
 #endif