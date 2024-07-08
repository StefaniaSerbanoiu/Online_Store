#include "HTML_Cart.h"


void HTML_Cart::writeToFile()
{
	ofstream of(this->filename);

	if (!of.is_open())
	{
		throw FileException("The HTML file can't be opened!!!");
	}


	int length = this->getCartLength();

	of << "<!DOCTYPE html>\n<html>\n<head>\n<title>Selected Products</title>\n</head>\n<body>\n<table border=" << 1 << ">\n<tr>\n";
	for (int i = 0; i < length; i++)
	{
		of << "<tr>\n";
		of << "<td><img src=\"" << this->getProductFromList(i).getPhotograph() << "\" style=\"width: 300px; height: 600px;\"></td>\n";
		of << "<td>" << this->getProductFromList(i).getSize() << "<td>\n";
		of << "<td>" << this->getProductFromList(i).getColor() << "<td>\n";
		of << "<td>" << this->getProductFromList(i).getPrice() << "<td>\n";
		of << "<td>" << this->getProductFromList(i).getQuantity() << "<td>\n";
		of << "</tr>\n";
	}
	of << "</table>\n</body>\n</html>";
	of.close();
}


void HTML_Cart::display() const
{
	std::string s = "C:\\Users\\anast\\OneDrive\\Documents\\Facultate\\Anul_1_Sem_2\\OOP\\Labs\\TrenchCoats_V2\\" + this->filename + "\"";
	ShellExecuteA(NULL, "open", "chrome.exe", s.c_str(), NULL, SW_SHOWMAXIMIZED);
}