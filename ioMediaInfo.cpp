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

#include "ioMediaInfo.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>

#define NAME_DEFAULT "Empty"
#define VALUE_DEFAULT 0.00
#define YEAR_DEFAULT 0
#define PRINT_DEFAULT false
#define AUTHOR_DEFAULT NULL
#define PAGE_DEFAULT 0


 ioMediaInfo::ioMediaInfo()
 {
  mediaItemName_ = NAME_DEFAULT;
  mediaItemYear_ = YEAR_DEFAULT;
  mediaItemPageNum_ = PAGE_DEFAULT;
  mediaItemPrint_ = PRINT_DEFAULT;
  mediaItemValue_ = VALUE_DEFAULT;
  mediaItemAuthor_ = 0;
 }
 
ioMediaInfo::~ioMediaInfo(){};

void ioMediaInfo::assignVariables(std::ofstream & _fstream, mediaInfo* originalMediaObject)
 {
     mediaItemName_ = originalMediaObject->getName();
     mediaItemYear_ = originalMediaObject->getYear(); 
     mediaItemPageNum_ = originalMediaObject->getPage();
     mediaItemPrint_ = originalMediaObject->getPrint();
     mediaItemValue_ = originalMediaObject->getValue();
     //mediaItemAuthor_ = originalMediaObject->getAuthor(); 
     
     
       _fstream.write(mediaItemName_.c_str(), mediaItemName_.length());
       //_fstream.write((const char *) &mediaItemAuthor_, sizeof(mediaItemAuthor_));
       _fstream.write((const char *) &mediaItemYear_, sizeof(mediaItemYear_));
       _fstream.write((const char *) &mediaItemValue_, sizeof(mediaItemValue_));
       _fstream.write((const char *) &mediaItemPrint_, sizeof(mediaItemValue_));
       _fstream.write((const char *) &mediaItemPageNum_, sizeof(mediaItemValue_));
 }