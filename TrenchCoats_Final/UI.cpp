#include "UI.h"
#include <iostream>


using namespace std;


// print functions 
void printSelectFileMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MODE SELECTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To use CSV, press 1.\n");
	cout << ("2. To use HTML, press 2.\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printSelectModeMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MODE SELECTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To continue as an administrator, press 1.\n");
	cout << ("2. To continue as an user, press 2.\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printAdminMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To see all products, press 1.\n");
	cout << ("2. To add a new product, press 2.\n");
	cout << ("3. To remove a product, press 3.\n");
	cout << ("4. To update the information about a product, press 4.\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printUserMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To see all products of a given size, press 1.\n");
	cout << ("2. To see the shopping basket and the total price of the items, press 2.\n");
	cout << ("3. To see the shopping basket in a file, press 3. (Don't forget about the extension :D  )\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printCartMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SHOPPING CART ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. If you want to add this item to your shopping cart, press 1.\n");
	cout << ("2. To move to the next one, press 2.\n");
	cout << ("*. To return, press 0.\n\n\n");
}


void play(string link)
{
	// we use Microsoft Edge to open the photos which are saved as links
	// from the cart, we get the element on the postion of the current index and get the photo
	// the photo ( saved as a string ) to to an array that contains a null-terminated sequence of characters 
	//																(i.e., a C-string, or const char*) 
	// after the shell is executed, a window is opened in a maximized form
	ShellExecuteA(NULL, NULL, "msedge.exe", link.c_str(), NULL, SW_SHOWMAXIMIZED);
}


void UI::printAllProducts()
{
	auto products = this->service->getRepo();

	// const is used to not accidentally modify something while iterating
	// 'auto&' ensures that the loop variable 'product' has the same type as the elements in the container being iterated over
	for (const auto& product : products->getAllObjectsFromRepository())
	{
		cout << product.getPhotograph() << "\ncolor: " << product.getColor() << "\nsize: " << product.getSize();
		cout << "\nprice: " << product.getPrice() << "\nquantity: " << product.getQuantity() << "\n\n";
	}
	cout << "\n\n";
}




//Validators
bool validSize(int size)
{
	if (size % 2 == 0 && size >= 32 && size <= 52)
	{
		return true;
	}
	return false;
}



bool validString(string input)
{
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		if (isdigit(input[i]))
		{
			return false;
		}
	}
	return true;
}


bool validColor(string color)
{
	int length = color.length();
	if (length < 3 || length > 15)
	{
		return false;
	}
	if (validString(color))
	{
		return true;
	}
	return false;
}


bool validQuantity(int q)
{
	if (q < 0)
	{
		return false;
	}
	return true;
}


bool validLink(string link)
{
	return false;
}


bool validPrice(int price)
{
	if (price < 30 || price > 99999)
	{
		return false;
	}
	return true;
}




//menu-running functions
void UI::runAdminMenu()
{
	int option = 1;
	while (option)
	{
		printAdminMenu();
		cout << "option : ";
		cin >> option;
		if (option == 1)
		{
			this->printAllProducts();
		}
		else if (option == 2)
		{
			this->addUI();
		}
		else if (option == 3)
		{
			this->deleteUI();
		}
		else if (option == 4)
		{
			this->updateUI();
		}
		else if (option == 0)
		{
			cout << "You no longer have admin rights.\n\n\n";
		}
		else
		{
			cout << "Incorrect option!!!\n";
		}
	}
}


void UI::runUserMenu(int storing_type)
{
	if (storing_type == 1)
	{
		CSV_Cart* final_list = new CSV_Cart();

		//the total sum of the purchases
		int sum = 0;

		int option = 1;
		while (option)
		{
			printUserMenu();
			cout << "option : ";
			cin >> option;
			if (option == 1)
			{
				int size;
				cout << "Introduce the size (0 if you want to see all products): ";
				cin >> size;
				while (((size % 2 == 0 && size >= 32 && size <= 52) || (size == 0)) == false)
				{
					cout << "The size is not correct!\n ";
					cout << "Introduce the size (0 if you want to see all products): ";
					cin >> size;
				}

				// creating a new cart and initializing it with the specified products
				// the function getBySize creates that cart
				ShoppingCart* list = this->service->getBySize(size);

				//this keeps the list going
				bool done = false;

				while (!done)
				{
					//get current product using the current index
					int index = list->getCurrentIndex();
					Product product = list->getProductFromList(index);
					string link = product.getPhotograph();

					//open the link
					play(link);

					//print current product
					cout << product.getPhotograph() << "\ncolor: " << product.getColor() << "\nsize: " << product.getSize();
					cout << "\nprice: " << product.getPrice() << "\nquantity: " << product.getQuantity() << "\n\n\n";

					printCartMenu();
					int option2 = 1;
					cout << "Introduce your option:";
					cin >> option2;

					if (option2 == 1)
					{
						// go to the next item
						list->next();

						//add a copy of the element to the shopping cart
						//elements cand be added more than once
						final_list->addProductToCart(Product(product));
						//to change this, we should modify the addProductToCart function to check for shared links
						//there is a modified version in Service.cpp, in case we want to add each item just once, uniquely


						//display the sum after updating it
						sum += product.getPrice();
						cout << "Yay! You added a new item to your cart!\n";
						cout << "          -total sum : " << sum << "\n\n\n";
					}
					else if (option2 == 2)
					{
						//go to the next item
						list->next();
						cout << "          -total sum : " << sum << "\n\n\n";
					}
					else if (option2 == 0)
					{
						done = true;
					}
					else
					{
						cout << "Invalid option!!!";
					}

				}

				//deleting the temporary filtered list used from browsing from memory
				delete list;
			}
			else if (option == 2)
			{
				cout << "All the items in your cart cost " << sum << ".\n\n";
				int length = final_list->getCartLength();
				for (int i = 0; i < length; i++)
				{
					Product product = final_list->getProductFromList(i);
					cout << product.getPhotograph() << "\ncolor: " << product.getColor() << "\nsize: " << product.getSize();
					cout << "\nprice: " << product.getPrice() << "\nquantity: " << product.getQuantity() << "\n\n";
				}
				cout << "\n\n";

			}
			else if (option == 3)
			{
				this->saveToCSV(final_list);
				this->service->openCart();
			}
			else if (option == 0)
			{
				cout << "You will be redirected to role selection.\n\n\n";
			}
			else
			{
				cout << "Incorrect option!!!\n";
			}
		}
		//deleting the shopping cart from memory
		delete final_list;
	}
	else
	{
		HTML_Cart* final_list = new HTML_Cart();

		//the total sum of the purchases
		int sum = 0;

		int option = 1;
		while (option)
		{
			printUserMenu();
			cout << "option : ";
			cin >> option;
			if (option == 1)
			{
				int size;
				cout << "Introduce the size (0 if you want to see all products): ";
				cin >> size;
				while (((size % 2 == 0 && size >= 32 && size <= 52) || (size == 0)) == false)
				{
					cout << "The size is not correct!\n ";
					cout << "Introduce the size (0 if you want to see all products): ";
					cin >> size;
				}

				// creating a new cart and initializing it with the specified products
				// the function getBySize creates that cart
				ShoppingCart* list = this->service->getBySize(size);

				//this keeps the list going
				bool done = false;

				while (!done)
				{
					//get current product using the current index
					int index = list->getCurrentIndex();
					Product product = list->getProductFromList(index);
					string link = product.getPhotograph();

					//open the link
					play(link);

					//print current product
					cout << product.getPhotograph() << "\ncolor: " << product.getColor() << "\nsize: " << product.getSize();
					cout << "\nprice: " << product.getPrice() << "\nquantity: " << product.getQuantity() << "\n\n\n";

					printCartMenu();
					int option2 = 1;
					cout << "Introduce your option:";
					cin >> option2;

					if (option2 == 1)
					{
						// go to the next item
						list->next();

						//add a copy of the element to the shopping cart
						//elements cand be added more than once
						final_list->addProductToCart(Product(product));
						//to change this, we should modify the addProductToCart function to check for shared links
						//there is a modified version in Service.cpp, in case we want to add each item just once, uniquely


						//display the sum after updating it
						sum += product.getPrice();
						cout << "Yay! You added a new item to your cart!\n";
						cout << "          -total sum : " << sum << "\n\n\n";
					}
					else if (option2 == 2)
					{
						//go to the next item
						list->next();
						cout << "          -total sum : " << sum << "\n\n\n";
					}
					else if (option2 == 0)
					{
						done = true;
					}
					else
					{
						cout << "Invalid option!!!";
					}

				}

				//deleting the temporary filtered list used from browsing from memory
				delete list;
			}
			else if (option == 2)
			{
				cout << "All the items in your cart cost " << sum << ".\n\n";
				int length = final_list->getCartLength();
				for (int i = 0; i < length; i++)
				{
					Product product = final_list->getProductFromList(i);
					cout << product.getPhotograph() << "\ncolor: " << product.getColor() << "\nsize: " << product.getSize();
					cout << "\nprice: " << product.getPrice() << "\nquantity: " << product.getQuantity() << "\n\n";
				}
				cout << "\n\n";

			}
			else if (option == 3)
			{
				this->saveToHTML(final_list);
				this->service->openCart();
			}
			else if (option == 0)
			{
				cout << "You will be redirected to role selection.\n\n\n";
			}
			else
			{
				cout << "Incorrect option!!!\n";
			}
		}
		//deleting the shopping cart from memory
		delete final_list;
	}
}


void UI::runMenu(int storing_type)
{
	int option = 1;
	while (option != 0)
	{
		printSelectModeMenu();
		cout << "option : ";
		cin >> option;
		if (option == 1)
		{
			runAdminMenu();
		}
		else if (option == 2)
		{
			runUserMenu(storing_type);
		}
		else if (option == 0)
		{
			cout << "The app is closing.\n";
		}
		else
		{
			cout << "Incorrect option!!!\n";
		}
	}
}


//admin functions
void UI::addUI()
{
	string link;
	int size_new;
	string color_new;
	int price_new;
	int quantity_new;

	cout << "Introduce a link to the product's photograph: ";
	cin >> link;

	if (this->service->findInRepoService(link) != -1)
	{
		cout << "The product couldn't be added because it already exists.\n";
	}
	else
	{
		cout << "Introduce the size: ";
		cin >> size_new;
		try
		{
			this->validator.validSize(size_new);
		}
		catch (ValidationException& ex)
		{
			cout << ex.what() << endl;
			size_new = 36;
		}

		cout << "Introduce the color: ";
		cin >> color_new;
		try 
		{
			this->validator.validColor(color_new);
		}
		catch (ValidationException& ex)
		{
			cout << ex.what() << endl;
			color_new = "no color";
		}

		cout << "Introduce the price: ";
		cin >> price_new;
		try
		{
			this->validator.validPrice(price_new);
		}
		catch (ValidationException& ex)
		{
			cout << ex.what() << endl;
			price_new = 30;
		}

		cout << "Introduce the quantity: ";
		cin >> quantity_new;
		try
		{
			this->validator.validQuantity(quantity_new);
		}
		catch (ValidationException& ex)
		{
			cout << ex.what() << endl;
			quantity_new = 0;
		}

		int result = this->service->addService(Product(size_new, color_new, price_new, quantity_new, link));

		if (result != -1)
		{
			cout << "The product was added to the database.\n";
		}
		else
		{
			cout << "The product couldn't be added.\n";
		}
	}
}


void UI::deleteUI()
{
	string link;

	cout << "Introduce a link to the trench product's photograph: ";
	cin >> link;

		try
		{
			this->service->removeService(link);
			cout << "The product was deleted from the database.\n";
		}
		catch (InexistentObjectException& exception)
		{
			cout << exception.messageFunction() << '\n';
		}
}


void UI::updateUI()
{
	string link, new_link;
	int size_new;
	string color_new;
	int price_new;
	int quantity_new;

	cout << "Introduce a link to the trench product's photograph: ";
	cin >> link;

	if (this->service->findInRepoService(link) == -1)
	{
		cout << "The product doesn't exist.\n";
	}
	else
	{
		cout << "Introduce the size: ";
		cin >> size_new;
		while (validSize(size_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the size: ";
			cin >> size_new;
		}

		cout << "Introduce the color: ";
		cin >> color_new;
		while (validColor(color_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the color: ";
			cin >> color_new;
		}

		cout << "Introduce the price: ";
		cin >> price_new;
		while (validPrice(price_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the price: ";
			cin >> price_new;
		}

		cout << "Introduce the quantity: ";
		cin >> quantity_new;
		while (validQuantity(quantity_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the quantity: ";
			cin >> quantity_new;
		}

		int result = this->service->updateService(link, size_new, color_new, price_new, quantity_new);

		if (result != -1)
		{
			cout << "The product was updated.\n";
		}
		else
		{
			cout << "The product couldn't be updated.\n";
		}
	}
}


//saving to different file formats
void UI::saveToCSV(CSV_Cart* cart)
{
	this->service->setCart(cart);
	std::string name_of_file;
	std::cout << "Introduce the name of the file: ";
	std::cin.get();
	std::getline(cin, name_of_file);

	try
	{
		this->service->saveCart(name_of_file);

		if (this->service->getCart() == nullptr)
		{
			cout << "The cart can't be shown.\n";
			return;
		}
	}
	catch (FileException& exception)
	{
		std::cout << exception.messageFunction();
	}
}


void UI::saveToHTML(HTML_Cart* cart)
{
	this->service->setCart(cart);
	std::string name_of_file;
	std::cout << "Introduce the name of the file: ";
	std::cin.get();
	std::getline(cin, name_of_file);

	try
	{
		this->service->saveCart(name_of_file);

		if (this->service->getCart() == nullptr)
		{
			cout << "The cart can't be shown.\n";
			return;
		}
	}
	catch (FileException& exception)
	{
		std::cout << exception.messageFunction();
	}
}