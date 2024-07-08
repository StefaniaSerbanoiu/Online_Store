#pragma once

#include <exception>
#include <string>



class RepositoryException : public std::exception
{
protected:
	std::string message;


public:
	RepositoryException();
	RepositoryException(const std::string& errorMessage);
	virtual ~RepositoryException() {}
	virtual const char* messageFunction();
};




class FileException : public std::exception
{
protected:
	std::string message;


public:
	FileException(const std::string& errorMessage);
	virtual const char* messageFunction();
};



class InexistentObjectException : public std::exception
{
public:
	const char* messageFunction();
};





class DuplicatedObjectException : public std::exception
{
public:
	virtual const char* messageFunction();
};

