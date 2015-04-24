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

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
      ar & mediaItemName_;
      ar & mediaItemYear_; 
      ar & mediaItemPageNum_;
      ar & mediaItemPrint_;
      ar & mediaItemValue_;
      ar & mediaItemAuthor_; 
      ar & mediaItemType_;
      ar & isEmpty_;
    } 

     std::string mediaItemName_;
     int mediaItemYear_; 
     int mediaItemPageNum_;
     bool mediaItemPrint_;
     bool isEmpty_;
     float mediaItemValue_;
     int mediaItemAuthor_; //used to associate an author
     std::string mediaItemType_;
  
  public:
  
     ioMediaInfo();
     
     ~ioMediaInfo();
     
     void assignVariables(mediaInfo*);

     std::string getName()
     {
      return mediaItemName_;
     };

     int getYear()
     {
      return mediaItemYear_;
     };

     int getPage()
     {
      return mediaItemPageNum_;
     };

     bool getPrint()
     {
      return mediaItemPrint_;
     };

     float getValue()
     {
      return mediaItemValue_;
     };

     float getAuthor()
     {
      return mediaItemAuthor_;
     };
     
     std::string getType()
     {
      return mediaItemType_;
     }

     bool getEmpty()
     {
      return isEmpty_;
     }

     void printData();
     //writeToFile();
  
     //readToFile();
     
 };//end of class
 #endif