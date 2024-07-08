#pragma once
#include "Product.h"



class ShoppingCart
{
protected:
	vector<Product> cart;
	int current_index;

public:
	//constructors
	// ShoppingCart() : cart{ new DynamicVector<Product>() }, current_index{ 0 } {}
	ShoppingCart() : cart{}, current_index{ 0 } {}
	ShoppingCart(vector<Product> products) : cart{ products }, current_index{ 0 } {}



	//getters
	/*
	the total number of elements in the shopping cart
	*/
	int getCartLength() { return cart.size(); }

	vector<Product> getVector() { return cart; }

	int getCurrentIndex();

	/*
	* return a pointer to the products available
	*/
	vector<Product> getAllProducts() const { return this->cart; }

	/*
	gets the product from a specific position(given as parameter)
	*/
	Product getProductFromList(int postion) const { return this->cart[postion]; }

	/*
	return a pointer to the current product
	*/
	Product getCurrentProduct();

	/*
	return the postion of a product with a given link, if the product exists
	-1 if it doesn't exist
	*/
	int getPosition(std::string link);



	bool isEmpty() { return this->getCartLength() == 0; }



	//CRUD 
	/*
	adds a new trench product to the cart
	returns 1 if the operation was successful
	returns 0 if the product already exists, so it can't be added
	*/
	int addProductToCart(const Product& product);
	/*
	deletes a product, given its photograph's link
	returns 1 if it was deleted
	returns 0 if it didn't already exist
	*/
	int deleteByLink(string link);


	int next();

	//destructor
	virtual ~ShoppingCart() {}
};