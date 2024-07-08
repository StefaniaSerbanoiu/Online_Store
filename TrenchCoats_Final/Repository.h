#pragma once
#include "Product.h"
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;



class Repository
{
private:
	vector<Product> objects; // the product are saved as std vector
	string file;


public:
	//constructor
	Repository(string name_of_file) : objects{}, file{ name_of_file } {}

	//getters
	vector<Product> getAllObjectsFromRepository() { return objects; }
	Product& getObjectOnPositionCopy(int position) const;
	Product getObjectOnPosition(int position) { return this->objects.at(position); }
	int getRepositorySize() const { return this->objects.size(); }

	/*
	returns -1 if the object wasn't found
	returns the position otherwise
	*/
	int findByLink(std::string link);

	//CRUD operations
	int addObject(const Product& object);
	int removeObject(const Product& object);
	int removeObjectByLink(std::string link);
	int updateObject(std::string link, int size_new, std::string color_new, int price_new, int quantity_new);

	void populate();


	void readFromFile();
	void writeToFile();
};