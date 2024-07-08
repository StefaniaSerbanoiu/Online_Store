#include "Product.h"
#include "ForStrings.h"


Product::Product(const int size, const std::string color, const int price, const int quantity, const std::string link)
	: size{ size }, color{ color }, price{ price }, quantity{ quantity }, photograph{ link } {}


bool Product::operator==(const Product& other)
{
	return this->color == other.getColor() &&
		this->photograph == other.getPhotograph() &&
		this->price == other.price &&
		this->quantity == other.quantity &&
		this->size == other.size;
}



//for file reading
std::istream& operator>>(std::istream& input, Product& product)
{
	std::string line;
	getline(input, line);

	std::vector<std::string> words = tokens(line, ',');

	int number_of_words = words.size();
	if (number_of_words < 5)
	{
		return input;
	}

	product.setPhotograph(trim(words[0]));
	product.setSize(std::stoi(trim(words[1])));
	product.setColor(trim(words[2]));
	product.setPrice(std::stoi(trim(words[3])));
	product.setQuantity(std::stoi(trim(words[4])));
	

	return input;
}



std::ostream& operator<<(std::ostream& output, const Product& product)
{
	output << product.getPhotograph() << ',';
	output << product.getSize() << ",";
	output << product.getColor() << ',' << product.getPrice() << ',' << product.getQuantity() << '\n';

	return output;
}