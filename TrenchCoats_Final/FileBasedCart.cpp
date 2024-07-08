#include "FileBasedCart.h"


FileBasedCart::FileBasedCart() :
	ShoppingCart{}, filename{ "" } {}


void FileBasedCart::setFileName(const string name)
{
	this->filename = name;
}