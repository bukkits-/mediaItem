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
#include "element.h"
#include "author.h"


#ifndef CLASSBODY_H
#define CLASSBODY_H
#define ELEMENTS 15 //Sets size of element array for each mediaInfo object
#define EMPTY_GENRE NONE
#define stringify( name ) # name
extern const char* GenreNames[];
///////////////////////////////////////////////////
// Memory reporting namespace for mediaItem objects
//
// Contains functions to track objects created and
// removed, and return the number alive
namespace objectAlive
{
  static int objectsAlive = 0;
  void addObject();
  void removeObject();
  int getAlive();
}

//enumeration for music genres
//
// NONE is included for use in the musicItem constructor as an initial value

enum Genre
  {ROCK, COUNTRY, HIPHOP, TECHNO, REGGAE, OTHER, NONE};

class mediaInfo
{
 
 private: 
   
  int itemYear_; 
  int currentElement_; //used to make sure that an element is not written to twice
  int itemPageNum_;
  bool itemPrint_;
  float itemValue_;
  Author *itemAuthor_; //used to associate an author
  mediaInfo *sequelItem_;
  Genre itemGenre_;

  mediaElement elementObject[ELEMENTS];

 public:

   std::string itemName_;
   bool objectEmpty_; 

//constructor/destructor - sets all attributes to initial values and increments object counter 

   mediaInfo();

   ~mediaInfo();

// Polymorphic functions

   virtual int rank() {return 100;}

   virtual std::string getISBN(){std::string blankISBN = ""; return blankISBN;};

   virtual void setISBN(std::string ISBN){};

   virtual void childPrintInfo(){};

   virtual float getMinutes(){float blankMinutes = 0.0; return blankMinutes;};

   virtual void setMinutes(float itemMinutes){};

   virtual void setDirector(std::string itemDirector){};

   virtual std::string getDirector(){std::string blankDirector = ""; return blankDirector;};

   virtual std::string getType();

   void setGenre(std::string genreInput);

   virtual Genre getGenre(){return EMPTY_GENRE;};
   
   bool checkRock(bool &checkGenre);
   
   bool checkCountry(bool &checkGenre);
   
   bool checkHipHop(bool &checkGenre);
   
   bool checkReggae(bool &checkGenre);
   
   bool checkTechno(bool &checkGenre);
   
   bool checkOther(bool &checkGenre);

   void setInfo (std::string itemName, float itemValue, int itemYear);

   void setElement(std::string elementName, int elementStart, int elementEnd);

   void printElements();

   std::string getName() {return itemName_;}

   void getAuthor();

   float getValue() {return itemValue_;}

   int getYear(){return itemYear_;}

   int getSequel();

   void setAuthor(Author* itemAuthor);

   void setName(std::string itemName);

   void setValue(float itemValue);

   void setYear(int itemYear);

   void setSequel(mediaInfo* sequelNum);

   int getPage() {return itemPageNum_; }

   void setPage(int itemPageNum);

   bool getPrint(){return itemPrint_;}

   void setPrint(bool itemPrint);

   bool isEmpty();
   
   void clearInfo();

   void printName();

   void returnInfo();
   
   //bool sortByName(const mediaInfo &lhs, const mediaInfo &rhs) { return lhs.itemName_ < rhs.itemName_; }
};

#endif
