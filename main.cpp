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
#include <exception>

#include "classBody.h"
#include "author.h"
#include "element.h"
#include "derived.h"
#include "Error_Derived.h"

#define AUTHORMAX 30
#define ELEMENTS 15
#define SELECT_INIT -1

//Global Variables
bool loopBool = true;
static Author authorObject[AUTHORMAX];
static std::vector<mediaInfo *> mediaObject;
int selectedAuthor = 0;
int selectedObject = SELECT_INIT;


// Prototypes
void optionSelect(char);
void menuDisplay();
bool stringCompare(mediaInfo*, mediaInfo*);
bool validObject(int);
bool stringCompareValue(mediaInfo*, mediaInfo*);
std::string menuInput();
void flushInput();

//////////////////////////////////////////////////////////////////////////////////////
// menuInput and intInput checks to make sure that cin has not failed

std::string menuInput()
{
  std::string menuInputString;
  std::cin >> menuInputString;

  if(std::cin.fail())
  {
    bool mainRecoverable = false;
    throw Input_Error(mainRecoverable);
  }
  return menuInputString;
}


int intInput()
{
  int intInputValue;
  std::cin >> intInputValue;

  if(std::cin.fail())
  {
    bool recoverableCin = true;
    throw Input_Error(recoverableCin);
  }
  return intInputValue;
}
//////////////////////////////////////////////////////////////////////////////////////
//stringCompare will sort the vector elements in ABC order based of the items name.
//
bool stringCompare(mediaInfo* m1, mediaInfo* m2)
{
  return m1->getName() < m2->getName();
}

/////////////////////////////////////////////////////////////////////////////////////
// Program's object index starting point is reserved 

bool validObject(int itemNumber)
{
  if(itemNumber == SELECT_INIT)
  {
    std::cout << "Please create an object first.\n";
    return false;
  }
  else
  {
    return true;
  }
}
//////////////////////////////////////////////////////////////////////////////////////
//stringCompareValue will sort the vector elements in order based off of the item 
//value.
//
bool stringCompareValue(mediaInfo* m1, mediaInfo* m2)
{
  return m1->getValue() < m2->getValue();
}

//menuDisplay function - displays menu
void menuDisplay ()
{
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
      if(validObject(selectedObject) == true)
      {
        mediaObject[selectedObject]->clearInfo();
      }
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
          mediaObject.push_back(new musicInfo());
          std::cout << "Music item created.\n";
          break;
        }

        case 'B':
        {
          mediaObject.push_back(new bookInfo());
          std::cout << "Book item created.\n";
          break;
        }

        case 'V':
        {
          mediaObject.push_back(new videoInfo());
          std::cout << "Video item created.\n";
          break;
        }

        default:
        {
          mediaObject.push_back(new mediaInfo());
          std::cout << "Default media item created.\n";
          break;
        }
      }
      break;
    }
  // Deletes currently selected mediaItem object
    case '-':
    {
      if(mediaObject[selectedObject]->isEmpty() != false && validObject(selectedObject) == true)
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
      if(mediaObject[selectedObject]->getType() == "M" || mediaObject[selectedObject]->getType() == "V" 
        && validObject(selectedObject) == true)
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
      try
      {
        yearBorn = intInput();
        if(yearBorn != 0) authorObject[selectedAuthor].setBorn(yearBorn);
      }
      catch(Input_Error yearError)
      {
        if(yearError.getRecoverable())
        {
          std::string inputFlush;
          std::cout << "Not a valid birth year choice.\n";
          std::cin.clear();
          getline(std::cin, inputFlush);
          return;
        }
        else
        {
          loopBool = false;
          return;
        }
      }
      catch(...)
      {
        std::cout << "You should not be seeing this error.";
        loopBool = false;
        return;
      }

      std::cout << yearBorn;
      std::cout << std::endl;

      std::cout << "Input author death year (0 if alive): ";
      try
      {
        yearDied = intInput();
        if(yearDied != 0) authorObject[selectedAuthor].setDied(yearDied);
      }
      catch(Input_Error yearError)
      {
        if(yearError.getRecoverable())
        {
          std::string inputFlush;
          std::cout << "Not a valid death year choice.\n";
          std::cin.clear();
          getline(std::cin, inputFlush);
          return;
        }
        else
        {
          loopBool = false;
          return;
        }
      }
      catch(...)
      {
        std::cout << "You should not be seeing this error.";
        loopBool = false;
        return;
      }
      
      std::cout << yearDied;
      std::cout << std::endl;

      std::cout << "Input author name: ";
      std::cin.ignore(1);
      getline(std::cin, itemAuthor);
      if(itemAuthor != "") authorObject[selectedAuthor].setName(itemAuthor);
      std::cout << itemAuthor;
      std::cout << std::endl;

      if(selectedAuthor < AUTHORMAX) //So when a new author is added it will not overwrite the last
      {
        selectedAuthor++;
      }
      break;
    }

  // Prints currently selected mediaItem attributes
    case 'D':
    {
      if(mediaObject[selectedObject]->isEmpty() == false && validObject(selectedObject) == true)
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

      if(validObject(selectedObject) == true)
      {  
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
      }
      break;
    }
    
  // Allows user to set a director or producer for music or video objects
    case 'F' :
    {
      std::string itemDirector;
      if(mediaObject[selectedObject]->getType() == "M" || mediaObject[selectedObject]->getType() == "V"
        && validObject(selectedObject) == true)
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
      if(mediaObject[selectedObject]->getType() == "B" && validObject(selectedObject) == true)
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
      if(mediaObject[selectedObject]->getType() == "B" && validObject(selectedObject) == true)
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
      
      getline(std::cin, genreInput);

      transform(genreInput.begin(), genreInput.end(), genreInput.begin(), ::toupper);
      
      if(validObject(selectedObject) == true && mediaObject[selectedObject]->getType() == "M")
      {
        std::string genreType1 = "ROC";
        std::string genreType2 = "COU";
        std::string genreType3 = "HIP";
        std::string genreType4 = "TEC";
        std::string genreType5 = "REG";
        std::cin.ignore(1,'\n');
        std::cout << "Please input genre: ";
        std::cout << std::endl << genreInput << std::endl;
        
        
        if (std::string::npos != genreInput.find(genreType1))
          {
          std::cout << "Made it in to Rock" << std::endl <<std::endl;
          genreInput = "Rock";
          mediaObject[selectedObject]->setGenre(genreInput);
          }
          
        if (std::string::npos != genreInput.find(genreType2))
          {
          genreInput = "Country";
          mediaObject[selectedObject]->setGenre(genreInput);
          }
         
        if (std::string::npos != genreInput.find(genreType3))
          {
          genreInput = "HipHop";
          mediaObject[selectedObject]->setGenre(genreInput);
          } 
        
        if (std::string::npos != genreInput.find(genreType4))
          {
          genreInput = "Techno";
          mediaObject[selectedObject]->setGenre(genreInput);
          }
          
        if (std::string::npos != genreInput.find(genreType5))
          {
          genreInput = "Reggae";
          mediaObject[selectedObject]->setGenre(genreInput);
          }    
         
         else
          {
            mediaObject[selectedObject]->setGenre(genreInput);
          }
        }
        else
        {
          std::cin.clear();
        }  
      break;
    }
    
   // Prints items out by Genre 
    case 'L':
    {
     int nArrayIncreaser;   
     
       std::cout << "======================Rock======================="<<std::endl;
       
         for (nArrayIncreaser = 0; nArrayIncreaser < mediaObject.size();++nArrayIncreaser)
           {
             bool genreChoice = false;
             mediaObject[nArrayIncreaser]->checkRock(genreChoice);
              if (genreChoice == true)
                {
                  std::cout << "Media item " << nArrayIncreaser << ":" << std::endl;
                  mediaObject[nArrayIncreaser]->returnInfo();
                  mediaObject[nArrayIncreaser]->getAuthor();
                  mediaObject[nArrayIncreaser]->getSequel();
                  mediaObject[nArrayIncreaser]->childPrintInfo();
                  mediaObject[nArrayIncreaser]->printElements();
                }
           } 
           
        std::cout << "======================Country======================="<<std::endl;
       
         for (nArrayIncreaser = 0; nArrayIncreaser < mediaObject.size();++nArrayIncreaser)
           {
             bool genreChoice = false;
             mediaObject[nArrayIncreaser]->checkCountry(genreChoice);
              if (genreChoice == true)
                {
                  std::cout << "Media item " << nArrayIncreaser << ":" << std::endl;
                  mediaObject[nArrayIncreaser]->returnInfo();
                  mediaObject[nArrayIncreaser]->getAuthor();
                  mediaObject[nArrayIncreaser]->getSequel();
                  mediaObject[nArrayIncreaser]->childPrintInfo();
                  mediaObject[nArrayIncreaser]->printElements();
                }
           } 
           
         std::cout << "======================HipHop======================="<<std::endl;
         for (nArrayIncreaser = 0; nArrayIncreaser < mediaObject.size();++nArrayIncreaser)
           {
             bool genreChoice = false;
             mediaObject[nArrayIncreaser]->checkHipHop(genreChoice);
              if (genreChoice == true)
                {
                  std::cout << "Media item " << nArrayIncreaser << ":" << std::endl;
                  mediaObject[nArrayIncreaser]->returnInfo();
                  mediaObject[nArrayIncreaser]->getAuthor();
                  mediaObject[nArrayIncreaser]->getSequel();
                  mediaObject[nArrayIncreaser]->childPrintInfo();
                  mediaObject[nArrayIncreaser]->printElements();
                }
           }
          
         std::cout << "======================Techno======================="<<std::endl;
         for (nArrayIncreaser = 0; nArrayIncreaser < mediaObject.size();++nArrayIncreaser)
           {
             bool genreChoice = false;
             mediaObject[nArrayIncreaser]->checkTechno(genreChoice);
              if (genreChoice == true)
                {
                  std::cout << "Media item " << nArrayIncreaser << ":" << std::endl;
                  mediaObject[nArrayIncreaser]->returnInfo();
                  mediaObject[nArrayIncreaser]->getAuthor();
                  mediaObject[nArrayIncreaser]->getSequel();
                  mediaObject[nArrayIncreaser]->childPrintInfo();
                  mediaObject[nArrayIncreaser]->printElements();
                }
           }
           
          std::cout << "======================Reggae======================="<<std::endl;
         for (nArrayIncreaser = 0; nArrayIncreaser < mediaObject.size();++nArrayIncreaser)
           {
             bool genreChoice = false;
             mediaObject[nArrayIncreaser]->checkReggae(genreChoice);
              if (genreChoice == true)
                {
                  std::cout << "Media item " << nArrayIncreaser << ":" << std::endl;
                  mediaObject[nArrayIncreaser]->returnInfo();
                  mediaObject[nArrayIncreaser]->getAuthor();
                  mediaObject[nArrayIncreaser]->getSequel();
                  mediaObject[nArrayIncreaser]->childPrintInfo();
                  mediaObject[nArrayIncreaser]->printElements();
                }
           }
           
          std::cout << "======================Other======================="<<std::endl;
         for (nArrayIncreaser = 0; nArrayIncreaser < mediaObject.size();++nArrayIncreaser)
           {
             bool genreChoice = false;
             mediaObject[nArrayIncreaser]->checkOther(genreChoice);
              if (genreChoice == true)
                {
                  std::cout << "Media item " << nArrayIncreaser << ":" << std::endl;
                  mediaObject[nArrayIncreaser]->returnInfo();
                  mediaObject[nArrayIncreaser]->getAuthor();
                  mediaObject[nArrayIncreaser]->getSequel();
                  mediaObject[nArrayIncreaser]->childPrintInfo();
                  mediaObject[nArrayIncreaser]->printElements();
                }
           }
      std::cout << std::endl;
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

      if(validObject(selectedObject) == true)
      {
        std::cin.ignore(1,'\n');
        std::cout << "Input media name: ";
        getline(std::cin, mediaItemName);
        std::cout << mediaItemName;
        mediaObject[selectedObject]->setName(mediaItemName); 
        std::cout << std::endl;
      }
      break;
    }

  // Sets page number of currently selected bookItem
    case 'P':
    {
      if(mediaObject[selectedObject]->getType() == "B" && validObject(selectedObject) == true)
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
      std::cout << "Author Object size: " << authorObjectBytes << " Bytes (Authors not dynamically allocated.)\n";
      std::cout << std::endl << "Total size of objects : " << mediaObjectBytes + authorObjectBytes << " Bytes" << std::endl;
      break;
    }

  // Sets sequel of current mediaItem
    case 'S':
    {
      int sequelNum;
      mediaInfo* pSetSequel;

      if(validObject(selectedObject) == true)
      {
        std::cin.ignore(1,'\n');
        std::cout << "Input sequel #: ";
        std::cin >> sequelNum;
        if(validObject(sequelNum) == true && sequelNum <= mediaObject.size())
        {
          pSetSequel = mediaObject[sequelNum];
          mediaObject[selectedObject]->setSequel(pSetSequel);

          std:: cout << std::endl << "Sequel set to ";

          mediaObject[sequelNum]->returnInfo();
          mediaObject[sequelNum]->getAuthor();
          mediaObject[sequelNum]->getSequel();
          mediaObject[sequelNum]->printElements();
          mediaObject[sequelNum]->childPrintInfo();
        }
        else
        {
          std::cout << "Sequel could not be set. (Outside range)\n";
        }
      }
      break;
    }

  // Sets author of current mediaItem
    case 'T':
    {
      int authorInput;
      Author* pAuthorSet;

      if(validObject(selectedObject) == true)
      {
        std::cout << "Input author number: ";
        std::cin >> authorInput;
        std::cout << authorInput << std::endl;
        pAuthorSet = &authorObject[authorInput];
        mediaObject[selectedObject]->setAuthor(pAuthorSet);
      }

      break;
    }

  //TODO: Implement sorting in "case: 'U'""
    case 'U':
    {
     std::cout << "== Media Items ==\n";
     
     char itemType;
     std::cin >> itemType;
     std::cout << itemType << std::endl;

     switch(toupper(itemType))
     {
     
       default:
         {
           std::sort(mediaObject.begin(), mediaObject.end(), stringCompare);
           for(int nMediaObjectIncreaser = 0; nMediaObjectIncreaser < mediaObject.size(); nMediaObjectIncreaser++)
             {
               if(mediaObject[nMediaObjectIncreaser]->isEmpty() == false)
                 {
                   std::cout << std::endl << std::endl << "Media item " << nMediaObjectIncreaser << ":" << std::endl;
                   mediaObject[nMediaObjectIncreaser]->returnInfo();
                   mediaObject[nMediaObjectIncreaser]->getAuthor();
                   mediaObject[nMediaObjectIncreaser]->getSequel();
                   mediaObject[nMediaObjectIncreaser]->childPrintInfo();
                   mediaObject[nMediaObjectIncreaser]->printElements();
                   std::cout << std::endl;
                 } 
              }
           }//end of default case
           
         case 'V'://case 'V' will sort by value.
           {
             std::sort(mediaObject.begin(), mediaObject.end(), stringCompareValue);
             for(int nMediaObjectIncreaser = 0; nMediaObjectIncreaser < mediaObject.size(); nMediaObjectIncreaser++)
             {
               if(mediaObject[nMediaObjectIncreaser]->isEmpty() == false)
                 {
                   std::cout << std::endl << std::endl << "Media item " << nMediaObjectIncreaser << ":" << std::endl;
                   mediaObject[nMediaObjectIncreaser]->returnInfo();
                   mediaObject[nMediaObjectIncreaser]->getAuthor();
                   mediaObject[nMediaObjectIncreaser]->getSequel();
                   mediaObject[nMediaObjectIncreaser]->childPrintInfo();
                   mediaObject[nMediaObjectIncreaser]->printElements();
                   std::cout << std::endl;
                 } 
              }
           }//end of case 'V'   
           
         case 'T'://case T will sort by the type of media item.
         {
              std::cout << std::endl << std::endl << "===========Book==============="<<std::endl;
                for (int nIncreaser = 0; nIncreaser < mediaObject.size(); nIncreaser++)
                  {
                    if ((mediaObject[nIncreaser]->rank()) == 100)
                     {
                       std::cout<< std::endl << std::endl << "Media item " << nIncreaser << ":" << std::endl;
                       mediaObject[nIncreaser]->returnInfo();
                       mediaObject[nIncreaser]->getAuthor();
                       mediaObject[nIncreaser]->getSequel();
                       mediaObject[nIncreaser]->childPrintInfo();
                       mediaObject[nIncreaser]->printElements();
                     }
                  }//end of for loop for type book.
               
               std::cout << std::endl << std::endl << "===========Video==============="<<std::endl;
                for (int nVideoIncreaser = 0; nVideoIncreaser < mediaObject.size(); nVideoIncreaser++)
                  {
                    if ((mediaObject[nVideoIncreaser]->rank()) == 300)
                     {
                       std::cout << std::endl << std::endl << "Media item " << nVideoIncreaser << ":" << std::endl;
                       mediaObject[nVideoIncreaser]->returnInfo();
                       mediaObject[nVideoIncreaser]->getAuthor();
                       mediaObject[nVideoIncreaser]->getSequel();
                       mediaObject[nVideoIncreaser]->childPrintInfo();
                       mediaObject[nVideoIncreaser]->printElements();
                     }
                  }//end of for loop for type video.
                  
                std::cout << std::endl << std::endl << "===========Music==============="<<std::endl;
                for (int nMusicIncreaser = 0; nMusicIncreaser < mediaObject.size(); nMusicIncreaser++)
                  {
                    if ((mediaObject[nMusicIncreaser]->rank()) == 200)
                     {
                       std::cout << std::endl << std::endl << "Media item " << nMusicIncreaser << ":" << std::endl;
                       mediaObject[nMusicIncreaser]->returnInfo();
                       mediaObject[nMusicIncreaser]->getAuthor();
                       mediaObject[nMusicIncreaser]->getSequel();
                       mediaObject[nMusicIncreaser]->childPrintInfo();
                       mediaObject[nMusicIncreaser]->printElements();
                     }
                  }//end of for loop for type music.  
                  
                std::cout << std::endl << std::endl << "===========Media Info==============="<<std::endl;
                for (int nMediaInfoIncreaser = 0; nMediaInfoIncreaser < mediaObject.size(); nMediaInfoIncreaser++)
                  {
                    if ((mediaObject[nMediaInfoIncreaser]->rank()) == 0)
                     {
                       std::cout << std::endl << std::endl << "Media item " << nMediaInfoIncreaser << ":" << std::endl;
                       mediaObject[nMediaInfoIncreaser]->returnInfo();
                       mediaObject[nMediaInfoIncreaser]->getAuthor();
                       mediaObject[nMediaInfoIncreaser]->getSequel();
                       mediaObject[nMediaInfoIncreaser]->childPrintInfo();
                       mediaObject[nMediaInfoIncreaser]->printElements();
                     }
                  }//end of for loop for type mediaInfo.  
                  
           }//end of 'T' 
      }
      break;
    }

  // Sets value of currently selected mediaItem

    case 'V':
    {
      float itemValue;

      if(validObject(selectedObject) == true)
      {
        std::cout << "Input item price: ";
        std::cin >> itemValue;
        std::cout << itemValue;
        try
        {
          mediaObject[selectedObject]->setValue(itemValue);
        }
        catch(std::exception valueRange)
        {
          std::cout << "Invalid/negative value.\n";
          return; 
        }
        catch(...)
        {
          std::cout << "You should not be seeing this error.\n";
        }
        std::cout << std::endl;
      }
      break;
    }

  // Sets release year of currently selected mediaItem
    case 'Y':
    {
      int itemYear;
      if(validObject(selectedObject) == true)
      {
        std::cout << "Input item publication year: ";
        std::cin >> itemYear;
        std::cout << itemYear;
        mediaObject[selectedObject]->setYear(itemYear);
        std::cout << std::endl;
      }
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
      if(selectedObject == SELECT_INIT)
      {
        std::cout << std::endl << "Menu (No Item): ";
      }
      else
      {
        std::cout << std::endl << "Item " << selectedObject << " Menu: ";
      }
      try
      {
        optionInput = menuInput();
      }
      catch(const Input_Error &)
      {
       std::cout << "Input error detected. Exiting.\n";
       break;
      }

      catch(...)
      {
        std::cout << "You should not be seeing this error message.\n";
        break;
      }
      std::cout << optionInput[0] << std::endl;    
      optionSelect(optionInput[0]); 
    }
  std:: cout << "Exiting\n" << std:: endl;
}
