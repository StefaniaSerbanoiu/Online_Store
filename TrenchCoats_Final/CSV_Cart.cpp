#include "CSV_Cart.h"


void CSV_Cart::writeToFile()
{
	ofstream of(this->filename);

	if (!of.is_open())
	{
		throw FileException("The CSV file can't be opened!!!");
	}

	for (auto object : this->cart)
	{
		of << object;
	}

	of.close();
}


void CSV_Cart::display() const
{
	string s = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, "open", "notepad.exe", s.c_str(), NULL, SW_SHOWMAXIMIZED);
}