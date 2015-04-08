/********************************************************************
Matthew Groeling
CS225

Assignment 6
main.cpp

In main.cpp, basic funcions are prototyped and defined.
'mediaItem' class handled in classBody.h and classBody.cpp.

main.cpp consists of menuDisplay(), optionSelect() and main():

menuDisplay() simply prints a menu of options. 

optionSelect() sorts input with case statements and calls
class functions.

main() is just a loop that gets input and passes it to optionSelect()

Uses code from Figure 2 of Lab 4 - Inheritance, specifically the 
mixed array initalization function

*********************************************************************/

#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include "classBody.h"
#include "author.h"
#include "element.h"
#include "derived.h"

#define AUTHORMAX 8
#define ELEMENTS 15

//Global Variables
bool loopBool = true;
static Author authorObject[AUTHORMAX];
static std::vector<mediaInfo *> mediaObject;
int selectedAuthor = 0;
int selectedObject = -1;


// Prototypes for optionSelect and menuDisplay
void optionSelect(char);
void menuDisplay();
bool stringCompare(mediaInfo*, mediaInfo*);

bool stringCompare(mediaInfo* m1, mediaInfo* m2)
{
  return m1->getName() < m2->getName();
}

//menuDisplay function - displays menu
void menuDisplay ()
{
  std::cout << "| Books | Music | Video | Media |\n";
  std::cout << "| 0-19  | 20-39 | 40-59 | 60-79 |\n\n";
  std::cout << "--------------Menu-------------\n";
  std::cout << "* : Display all item data\n";
  std::cout << "# : Select by item number\n";
  std::cout << "+ : Move forward to next item\n";
  std::cout << "- : Return to previous item\n";
  std::cout << "0 : Clear item data\n";
  std::cout << "B:  Set duration/time\n";
  std::cout << "C : Create new author\n";
  std::cout << "D : Display item data\n";
  std::cout << "E : Set element info\n";
  std::cout << "F:  Set music producer or video director\n";
  std::cout << "I : Set item in print status\n";
  std::cout << "J : Set item ISBN\n";
  std::cout << "M : Display main menu\n";
  std::cout << "N : Set item name\n";
  std::cout << "P : Set item pages\n";
  std::cout << "S : Set item sequel\n";
  std::cout << "T : Set item author\n";
  std::cout << "V : Set item value\n";
  std::cout << "Y : Set item publication year\n";
  std::cout << "Q : Quit\n";
  std::cout << "--------------------------------\n"; 
  std::cout << std::endl;
}

//optionSelect - sorts input with case statements
//Case statements organized into sections based on function
void optionSelect(char inputChar)
{
  std::cout << std::endl;
  switch (toupper(inputChar))
  {

  //Clears all data fields for selected object
    case '0':
    {
      mediaObject[selectedObject]->clearInfo();
      break;
    }

  // Displays data for all objects (*)
    case '*':
    {
      int itemCount = 0;
      int authorCount = 0; // these will be used to count the number of items that are printed
      std::cout << "== Media Items ==\n";
      for(int i = 0; i < mediaObject.size(); i++)
      {
        if(mediaObject[i]->isEmpty() == false)
        {
          std::cout << "Media item " << i << ":" << std::endl;
          mediaObject[i]->returnInfo();
          mediaObject[i]->getAuthor();
          mediaObject[i]->getSequel();
          mediaObject[i]->childPrintInfo();
          mediaObject[i]->printElements();
          itemCount++;
          std::cout << std::endl;
        }
      }    
      //Gives a count of number of items returned to user or informs user that no objects with modified data were found.    
      if(itemCount > 0)
      {std::cout << "\nFound " << itemCount << " item(s).\n";}
      else
      {std::cout << "No items found.\n";}

      std::cout << std::endl;
      std::cout << "== Author Items ==\n";

      for(int i = 0; i < AUTHORMAX; i++)
      {
        if(authorObject[i].isActive() == true)
          {
            std::cout << "Author " << i << ": \n";
            authorObject[i].returnInfo();
            std::cout << std::endl;
            authorCount++;
          }
      }
      if(authorCount > 0)
        {std::cout << "Found " << authorCount << " author(s).\n";}
      else
        {std::cout << "No authors found.\n";}

      break;
    }

  // Used for comments
    case '/':
    {
      std::string scriptComment;
      getline(std::cin, scriptComment);
      if(scriptComment != "")
        {std:: cout << "//" << scriptComment << std::endl;}
      break;
    }

  // Adds a new mediaItem object, asks for input to select type of mediaItem object to create
    case '+':
    { 
      std::string itemType;
      selectedObject++;

      std::cin.ignore(1,'\n');
      std::cout << "Create a new item\n";
      std::cout << "[M]usic, [B]ook, [V]ideo, or [*] : ";
      std::cin >> itemType;
      std::cout << itemType[0] << std::endl;

      switch(toupper(itemType[0]))
      {
        case 'M':
        {
          mediaObject.resize(selectedObject + 1);
          //mediaObject.push_back(new musicInfo());
          mediaObject[selectedObject] = new musicInfo();
          std::cout << "Music item created.\n";
          break;
        }

        case 'B':
        {
          mediaObject.resize(selectedObject + 1);
          mediaObject[selectedObject] = new bookInfo();
          std::cout << "Book item created.\n";
          break;
        }

        case 'V':
        {
          mediaObject.resize(selectedObject + 1);
          mediaObject[selectedObject] = new videoInfo();
          std::cout << "Video item created.\n";
          break;
        }

        default:
        {
          mediaObject.resize(selectedObject + 1);        
          mediaObject[selectedObject] = new mediaInfo();
          std::cout << "Default media item created.\n";
          break;
        }
      }
      break;
    }
  // Deletes currently selected mediaItem object
    case '-':
    {
      if(mediaObject[selectedObject]->isEmpty() != false)
      {
        delete mediaObject[selectedObject];
      }
      break;
    }  

  // Selects mediaItem object by index number
    case '#':
    {
      bool selectBool = true;
      int itemSelectNumber;
      while(selectBool==true)
      {
        std::cout << "Input item number: ";
        std::cin >> itemSelectNumber;
        std::cout << std::endl;
        if(itemSelectNumber < mediaObject.size() && itemSelectNumber>=0)
        {
          selectedObject = itemSelectNumber;
          std::cout << "  Item " << selectedObject << " selected.\n";
          selectBool = false;
        }
        else
        {
          std::cout << "Outside range (0-" << mediaObject.size() <<")\n";
        }
      }
      break;
    }

  // Sets attribute itemMinutes in derived music or video class
    case 'B' :
    {
      float itemMinutes;
      if(mediaObject[selectedObject]->getType() == "M" || mediaObject[selectedObject]->getType() == "V")
      {
        std::cout << "Enter item time: ";
        std::cin >> itemMinutes;
        std::cout << std::endl;
        mediaObject[selectedObject]->setMinutes(itemMinutes);
      }
      else
      {
        std::cout << "Item is not music or video.\n";
      }
    break;
    }

  // Creates a new author and prompts user to enter author name, birth year and year of death 
    case 'C':
    {
      std::string itemAuthor;
      int yearBorn;
      int yearDied;

      std::cout << "Input author birth year: ";
      std::cin >> yearBorn;
      std::cout << yearBorn;
      std::cout << std::endl;
      if(yearBorn != 0)
      {
        authorObject[selectedAuthor].setBorn(yearBorn);
      }

      std::cout << "Input author death year (0 if alive): ";
      std::cin >> yearDied;
      std::cout << yearDied;
      std::cout << std::endl;
      if(yearDied != 0)
      {
        authorObject[selectedAuthor].setDied(yearDied);
      }

      std::cout << "Input author name: ";
      std::cin.ignore(1);
      getline(std::cin, itemAuthor);
      std::cout << itemAuthor;
      std::cout << std::endl;
      authorObject[selectedAuthor].setName(itemAuthor);

      if(selectedAuthor < AUTHORMAX) //So when a new author is added it will not overwrite the last
      {
        selectedAuthor++;
      }
      break;
    }

  // Prints currently selected mediaItem attributes
    case 'D':
    {
      if(mediaObject[selectedObject]->isEmpty() == false)
      {
        mediaObject[selectedObject]->returnInfo();
        mediaObject[selectedObject]->getAuthor();
        mediaObject[selectedObject]->getSequel();
        mediaObject[selectedObject]->childPrintInfo();
        mediaObject[selectedObject]->printElements();
      }
      else
      {
        std::cout << "Item " << selectedObject << " is empty.\n";
      }
       break;
    }

  // Adds a new element, prompts user for element information
    case 'E':
    {
      std::string elementName;
      int elementStart;
      int elementEnd;

      std::cout << "Input element start: ";
      std::cin >> elementStart;
      std::cout << std::endl;

      std::cout << "Input element end: ";
      std::cin >> elementEnd;
      std::cout << std::endl;;

      std::cout << "Input element name: ";
      std::cin.ignore(1);
      getline(std::cin, elementName);
      std::cout << std::endl;

      mediaObject[selectedObject]->setElement(elementName, elementStart, elementEnd);
      break;
    }
    
  // Allows user to set a director or producer for music or video objects
    case 'F' :
    {
      std::string itemDirector;
      if(mediaObject[selectedObject]->getType() == "M" || mediaObject[selectedObject]->getType() == "V")
      {
        std::cout << "Enter music producer or video director: ";
        getline(std::cin, itemDirector);
        std::cout << std::endl;
        mediaObject[selectedObject]->setDirector(itemDirector);
      }
      else
      {
        std::cout << "Item is not music or video.\n";
      }
      break;
    }

  // Sets the print status (in print or not) of currently selected mediaItem
    case 'I':
    {
      if(mediaObject[selectedObject]->getType() == "B")
      {
        bool inPrint;
        std::cout << "Is item in print? [0/1]: ";
        std::cin >> inPrint;
        std::cout << std::endl;
        mediaObject[selectedObject]->setPrint(inPrint);
      }
      else
      {
        std::cout << "Currently selected item is not a book.";
      }
      break;
    }

  // Sets ISBN of currently selected bookItem 
    case 'J':
    {
      if(mediaObject[selectedObject]->getType() == "B")
      {
        std::string itemISBN;
        std::cout << "Enter ISBN: ";
        std::cin >> itemISBN;
        std::cout << std::endl;
        mediaObject[selectedObject]->setISBN(itemISBN);
      }
      else
      {
        std::cout << "Currently selected item is not a book.";
      }
      break;
    }

  // Sets Genre of currently selected musicItem 
    case 'K':
    {
      std::string genreInput;
      std::cin.ignore(1,'\n');
      std::cout << "Please input genre: ";
      getline(std::cin, genreInput);
      std::cout << std::endl << genreInput << std::endl;
      mediaObject[selectedObject]->setGenre(genreInput);
      break;
    }

  // Displays menu of options
    case 'M':
    {
      menuDisplay();
      break;
    }

  // Sets name of mediaItem object
    case 'N':
    {
      std::string mediaItemName;

      std::cin.ignore(1,'\n');
      std::cout << "Input media name: ";
      getline(std::cin, mediaItemName);
      std::cout << mediaItemName;
      mediaObject[selectedObject]->setName(mediaItemName); 
      std::cout << std::endl;
      break;
    }

  // Sets page number of currently selected bookItem
    case 'P':
    {
      if(mediaObject[selectedObject]->getType() == "B")
      {
        int inputPageNum;
        std::cout << "Input page number: ";
        std::cin >> inputPageNum;
        std::cout << std::endl;
        mediaObject[selectedObject]->setPage(inputPageNum);
      }
      else
      {
        std::cout << "Currently selected item is not a book.";
      }
      break;
    }

  // Sets loopbool to false, ending program execution
    case 'Q':
    {
      loopBool = false;
      break;
    }

  // Reports memory usage
    case 'R':
    {
      int mediaObjectBytes = 0;
      int authorObjectBytes = 0;
      for(int i = 0; i <= mediaObject.size(); i++)
      {
        mediaObjectBytes = sizeof(mediaObject[i]) + mediaObjectBytes;
      }
      for(int i = 0; i < AUTHORMAX; i++)
      {
        if(authorObject[i].isActive() == true)
          {
            authorObjectBytes = sizeof(authorObject[i]) + authorObjectBytes;
          }
      }

      std::cout << "There are " << objectAlive::getAlive() << " media objects in memory.\n";
      std::cout << "Media Object size: " << mediaObjectBytes << " Bytes \n";
      std::cout << "Authors in memory: " << objectAuthorAlive::getAuthorAlive() << " author objects in memory.\n";
      std::cout << "Author Object size: " << authorObjectBytes << " Bytes \n";
      std::cout << std::endl << "Total size of objects : " << mediaObjectBytes + authorObjectBytes << " Bytes" << std::endl;
      break;
    }

  // Sets sequel of current mediaItem
    case 'S':
    {
      int sequelNum;
      mediaInfo* pSetSequel;

      std::cin.ignore(1,'\n');
      std::cout << "Input sequel #: ";
      std::cin >> sequelNum;
      pSetSequel = mediaObject[sequelNum];
      mediaObject[selectedObject]->setSequel(pSetSequel);

      std:: cout << std::endl << "Sequel set to ";

      mediaObject[sequelNum]->returnInfo();
      mediaObject[sequelNum]->getAuthor();
      mediaObject[sequelNum]->getSequel();
      mediaObject[sequelNum]->printElements();
      mediaObject[sequelNum]->childPrintInfo();

      break;
    }

  // Sets author of current mediaItem
    case 'T':
    {
      int authorInput;
      Author* pAuthorSet;

      std::cout << "Input author number: ";
      std::cin >> authorInput;
      std::cout << authorInput << std::endl;
      pAuthorSet = &authorObject[authorInput];
      mediaObject[selectedObject]->setAuthor(pAuthorSet);

      break;
    }

  //TODO: Implement sorting in "case: 'U'""
    case 'U':
    {
     //This doesn't really sort anything yet because mediaObject points to classes, not an int or string value
	   std::sort(mediaObject.begin(), mediaObject.end(), stringCompare);
     std::cout << "Sort complete.\n";
     std::cout << "== Media Items ==\n";
     for(int i = 0; i < mediaObject.size(); i++)
     {
       if(mediaObject[i]->isEmpty() == false)
        {
          std::cout << "Media item " << i << ":" << std::endl;
          mediaObject[i]->returnInfo();
          mediaObject[i]->getAuthor();
          mediaObject[i]->getSequel();
          mediaObject[i]->childPrintInfo();
          mediaObject[i]->printElements();
          std::cout << std::endl;
        }
      } 
      break;
    }

  // Sets value of currently selected mediaItem

    case 'V':
    {
      float itemValue;
      std::cout << "Input item price: ";
      std::cin >> itemValue;
      std::cout << itemValue;
      mediaObject[selectedObject]->setValue(itemValue);
      std::cout << std::endl;
      break;
    }

  // Sets release year of currently selected mediaItem
    case 'Y':
    {
      int itemYear;
      std::cout << "Input item publication year: ";
      std::cin >> itemYear;
      std::cout << itemYear;
      mediaObject[selectedObject]->setYear(itemYear);
      std::cout << std::endl;
      break;
    }

  }
}

// Main displays the menu and then enters into a while loop that recieves input and
// uses optionSelect to test against the different cases
int main()
{
  std::string optionInput;
  menuDisplay();

  while (loopBool)
    {
      std::cin.clear();
      if(selectedObject == -1)
      {
        std::cout << std::endl << "Menu (No Item): ";
      }
      else
      {
        std::cout << std::endl << "Item " << selectedObject << " Menu: ";
      }
      std::cin >> optionInput;
      std::cout << optionInput[0] << std::endl;    
      optionSelect(optionInput[0]); 
    }
  std:: cout << "Exiting\n" << std:: endl;
}