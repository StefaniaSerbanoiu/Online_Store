#pragma once
#include "Product.h"



class ValidationException : public std::exception 
{
private:
    string message;

public:
	explicit ValidationException(string _msg) : message{ _msg } {}
	const char* what() const noexcept override { return message.c_str(); }
};


class Validator 
{
public:
    Validator();
	~Validator();

	//Validators functions for Product attributes

	bool validSize(int size);
	bool validString(string input);
	bool validColor(string color);
	bool validQuantity(int q);
	bool validLink(string link) { return true; }
    bool validPrice(int price);
	bool validateString(const std::string& input);
};
