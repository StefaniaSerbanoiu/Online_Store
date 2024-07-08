#include "Service.h"
#include <iostream>

//constructor
Service::Service(Repository* repository, FileBasedCart* cart)
	: repo{ repository }, cart{ cart } {}



//REPO functions
// 
// 
//getters
Product Service::getProductFromRepository(int position)
{
	return (Product&)this->repo->getObjectOnPosition(position);
}


//CRUD for Repository
int Service::addService(const Product& product)
{
	return this->repo->addObject(product);

}


int Service::removeService(std::string link)
{
	int result = this->repo->removeObjectByLink(link);
	if (result == -1)
	{
		throw InexistentObjectException();
	}
	else
	{
		return result;
	}
}


int Service::updateService(std::string link, int size_new, std::string color_new, int price_new, int quantity_new)
{
	return this->repo->updateObject(link, size_new, color_new, price_new, quantity_new);
}


// find function
/*
	returns -1 if the object wasn't found or the index is not valid
	returns the position of the element otherwise
*/
int Service::findInRepoService(std::string link)
{
	return this->repo->findByLink(link);
}



//SHOPPING CART functions

ShoppingCart* Service::getBySize(int size)
{
	// we add a copy of each item from the repo into a new DynamicVector<Product> pointer
	vector<Product> list;
	int length = this->getRepoSize();
	Repository* repo = this->getRepo();
	for (int i = 0; i < length; i++)
	{
		Product t = Product(repo->getObjectOnPosition(i));
		list.push_back(t);
	}

	// we create a new cart in which we add the wanted items
	ShoppingCart* cart = new ShoppingCart();

	if (size == 0) // for this number, the size doens't matter and all products are added
	{
		for (int i = 0; i < length; i++)
		{
			cart->addProductToCart(list[i]);
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			int elemSIze = list[i].getSize();
			if (elemSIze == size)
			{
				cart->addProductToCart(list[i]);
			}
		}
	}

	return cart;
}


CSV_Cart* Service::getBySize1(int size)
{
	// we add a copy of each item from the repo into a new DynamicVector<Product> pointer
	vector<Product> list;
	int length = this->getRepoSize();
	Repository* repo = this->getRepo();
	for (int i = 0; i < length; i++)
	{
		Product t = Product(repo->getObjectOnPosition(i));
		list.push_back(t);
	}

	// we create a new cart in which we add the wanted items
	// there are 2 options of carts to create, depending on storing type
	// this is the version for a cart stored in a CSV file
		CSV_Cart* cart = new CSV_Cart();

		if (size == 0) // for this number, the size doens't matter and all products are added
		{
			for (int i = 0; i < length; i++)
			{
				cart->addProductToCart(list[i]);
			}
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				int elemSIze = list[i].getSize();
				if (elemSIze == size)
				{
					cart->addProductToCart(list[i]);
				}
			}
		}

		return cart;
}


HTML_Cart* Service::getBySize2(int size)
{
	// we add a copy of each item from the repo into a new DynamicVector<Product> pointer
	vector<Product> list;
	int length = this->getRepoSize();
	Repository* repo = this->getRepo();
	for (int i = 0; i < length; i++)
	{
		Product t = Product(repo->getObjectOnPosition(i));
		list.push_back(t);
	}

	// we create a new cart in which we add the wanted items
	// there are 2 options of carts to create, depending on storing type
	// this is the version for a cart stored in a HTML file
	HTML_Cart* cart = new HTML_Cart();

	if (size == 0) // for this number, the size doens't matter and all products are added
	{
		for (int i = 0; i < length; i++)
		{
			cart->addProductToCart(list[i]);
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			int elemSIze = list[i].getSize();
			if (elemSIze == size)
			{
				cart->addProductToCart(list[i]);
			}
		}
	}

	return cart;
}


//for saving the cart in different file formats
void Service::saveCart(const std::string& filename)
{
	if (this->cart == nullptr)
		return;

	this->cart->setFileName(filename);
	this->cart->writeToFile();
}


void Service::openCart() const
{
	if (this->cart == nullptr)
		return;

	this->cart->display();
}

