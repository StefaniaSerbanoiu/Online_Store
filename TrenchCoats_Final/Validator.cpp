#include "Validator.h"


// Validator class constructor
Validator::Validator() = default;


bool Validator::validateString(const string & input) 
{
    for (char i : input)
    {
        if (isdigit(i) != false)
        {
            return false;
        }
    }
    return true;
}


//Validator functions for different TrenchCoat attributes

bool Validator::validSize(int size)
{
    if (size % 2 == 0 && size >= 32 && size <= 52)
    {
        return true;
    }
    throw ValidationException(string("The size is not a valid number!"));
}



bool Validator::validString(string input)
{
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}


bool Validator::validColor(string color)
{
    string errors;
    int length = color.length();
    if (length < 3 || length > 15)
    {
        errors += string("The color doesn't exist!");
    }
    if (!validString(color))
    {
        errors += string("The color contains digits!");
    }
    if (!errors.empty())
    {
        throw ValidationException(errors);
    }
    return true;
}


bool Validator::validQuantity(int q)
{
    if (q < 0)
    {
        throw ValidationException("The quantity is negative!");
    }
    return true;
}


bool Validator::validPrice(int price)
{
    if (price < 30 || price > 99999)
    {
        throw ValidationException("The price is either too low ( <30 ) or too high ( > 99999 )!");
    }
    return true;
}


// Validator class destructor
Validator::~Validator() = default;