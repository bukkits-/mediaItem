/********************************************************************
Matthew Groeling
Joe Mehltretter
CS225

Assignment 6
Error_Derived.h

Inherits from exception.

*********************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>

#define RECOVERABLE_DEFAULT true

class Input_Error : public std::exception
{
private:
	bool recoverableError_;
public:
	Input_Error(bool recoverableError = RECOVERABLE_DEFAULT)
	{
		recoverableError_ = recoverableError;
	};

	bool getRecoverable(){return recoverableError_;};
};
