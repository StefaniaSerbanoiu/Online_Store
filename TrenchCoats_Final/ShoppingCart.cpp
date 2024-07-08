#include "ShoppingCart.h"



Product ShoppingCart::getCurrentProduct()
{
	if (this->current_index == this->cart.size())
	{
		this->current_index = 0;
	}
	Product currentProduct = this->getProductFromList(this->current_index);
	return currentProduct;
}


int ShoppingCart::getCurrentIndex()
{
	return this->current_index;
}


int ShoppingCart::getPosition(std::string link)
{
	int ct = 0;
	for (const auto& product : this->getAllProducts())
	{
		if (product.getPhotograph() == link)
		{
			return ct;
		}
		ct++;
	}
	return -1;
}



//CRUD
int ShoppingCart::addProductToCart(const Product& product)
{
	//this allows shopping more products of the same type
	//this is so because there is no check for unicity
	this->cart.push_back(product);
	return 1;

	// modified version to add each item just once
	/*
	if (this->getPosition(product.getPhotograph()) == -1)
	{
		this->cart->add(product);
		return 1;
	}
	return 0;
	*/
}


int ShoppingCart::deleteByLink(std::string link)
{
	/*
	int position = this->getPosition(link);
	if (position != -1)
	{
		auto iterator = find(this->cart.begin(), this->cart.end(), this->getProductFromList(position));
		this->cart.erase(iterator);
		return 1;
	}
	*/
	return 0;
}


int ShoppingCart::next()
{
	if (this->isEmpty() == false)
	{
		this->current_index++;
		std::cout << this->current_index;
		Product currentProduct = this->getCurrentProduct();
		std::cout << currentProduct.getPrice();
	}
	return 1;
}


