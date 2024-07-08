#pragma once
#include "ShoppingCart.h"
#include <fstream>
#include <Windows.h>


class FileBasedCart : public ShoppingCart
{
protected:
	std::string filename;

public:
	FileBasedCart();
	~FileBasedCart() {}

	void setFileName(const std::string name);
	virtual void writeToFile() = 0;
	virtual void display() const = 0;

};
