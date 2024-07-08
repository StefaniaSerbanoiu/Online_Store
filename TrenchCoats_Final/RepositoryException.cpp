#include "RepositoryException.h"


FileException::FileException(const std::string& errorMessage) : message(errorMessage)
{
}


const char* FileException::messageFunction()
{
	return message.c_str();
}




RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}


RepositoryException::RepositoryException(const std::string& errorMessage) : message{ errorMessage }
{
}


const char* RepositoryException::messageFunction()
{
	return message.c_str();
}




const char* DuplicatedObjectException::messageFunction()
{
	return "Error! The product already exists!\n";
}




const char* InexistentObjectException::messageFunction()
{
	return "Error! There is no product with that link!\n";
}
