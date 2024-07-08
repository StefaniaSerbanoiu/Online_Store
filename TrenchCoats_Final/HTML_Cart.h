#pragma once
#include "FileBasedCart.h"


class HTML_Cart : public FileBasedCart
{
public:
	void display() const override;
	void writeToFile() override;
};