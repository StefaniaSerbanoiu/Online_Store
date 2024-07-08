#pragma once
#include "Repository.h"
#include "CSV_Cart.h"
#include "HTML_Cart.h"


class Service
{
private:
	Repository* repo;
	FileBasedCart* cart;

public:
	//constructor
	Service(Repository* repository, FileBasedCart* cart);

	//getters
	Repository* getRepo() const { return this->repo; }
	ShoppingCart* getCart() const { return this->cart; }
	Product getProductFromRepository(int position);
	int getRepoSize() const { return this->repo->getRepositorySize(); }

	//setters
	void setCart(FileBasedCart* other) { this->cart = other; }

	//CRUD for Repository
	int addService(const Product& product);
	int removeService(string link);
	int updateService(string link, int size_new, string color_new, int price_new, int quantity_new);


	/*returns - 1 if the object wasn't found or the index is not valid
	 returns the position of the element otherwise
	*/
	int findInRepoService(string link);



	//Shopping Cart Functions
	ShoppingCart* getBySize(int size);
	CSV_Cart* getBySize1(int size);
	HTML_Cart* getBySize2(int size);

	//for saving the cart in different file formats
	void saveCart(const string& filename);
	void openCart() const;
};