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

void ioMediaInfo::assignVariables(mediaInfo* originalMediaObject)
 {
     mediaItemName_ = originalMediaObject->getName();
     mediaItemYear_ = originalMediaObject->getYear(); 
     mediaItemPageNum_ = originalMediaObject->getPage();
     mediaItemPrint_ = originalMediaObject->getPrint();
     mediaItemValue_ = originalMediaObject->getValue();
     mediaItemType_ = originalMediaObject->getType();
     isEmpty_ = originalMediaObject->isEmpty();
     //mediaItemAuthor_ = originalMediaObject->getAuthor(); 
 }

 void ioMediaInfo::printData()
 {
  std::cout << mediaItemName_ << std::endl;


 }
