#pragma once
#include "Service.h"
#include "Validator.h"


class UI
{
private:
	Service* service;
	Validator validator;

	void printAllProducts();

	//menus for the roles
	void runAdminMenu();
	void runUserMenu(int storing_type);

	//admin functions
	void addUI();
	void deleteUI();
	void updateUI();

	void saveToCSV(CSV_Cart* cart);
	void saveToHTML(HTML_Cart* cart);

public:
	//constructor
	UI(Service* new_service, Validator v) : service{ new_service }, validator{ v } {}

	void runMenu(int storing_type);
};


void printSelectFileMenu();