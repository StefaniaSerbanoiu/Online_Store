#include "Products_Final.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Tests.h"
#include "Validator.h"
#include "GUI.h"


int main(int argc, char* argv[])
{
    int storing_type = 1;
    while (storing_type != 1 && storing_type != 2 && storing_type != 0)
    {
    }

    if (storing_type)
    {
        try
        {
            Repository* repository = new Repository("Coats.txt");
            repository->readFromFile();
            CSV_Cart* cart1 = new CSV_Cart();
            HTML_Cart* cart2 = new HTML_Cart();
            Service* service = new Service(repository, cart1);
            if (storing_type == 2)
            {
                service->setCart(cart2);
            }

            Validator v;
            //UI* ui = new UI(service, v);
           // ui->runMenu(storing_type);\

            QApplication a(argc, argv);
            GUI gui(*service);
            gui.show();
            Products_Final w;
            w.show();
            return a.exec();

            //delete ui;
            delete service;
            cart1->getAllProducts().~vector();
            delete cart1;
            cart2->getAllProducts().~vector();
            delete cart2;
            delete repository;



        }

        catch (FileException&)
        {
            return -25;
        }
    }

   
}




/*
#include <iostream>
#include "UI.h"
#include "Tests.h"
#define _CRTDBG_MAP_ALLOC
#include "RepositoryException.h"



int main()
{
    printSelectFileMenu();
    int storing_type = 0;
    std::cout << "option: ";
    std::cin >> storing_type;
    while (storing_type != 1 && storing_type != 2 && storing_type != 0)
    {
        std::cout << "The number doesn't correspond to any method of storing events. Please try again!\n";
        std::cin >> storing_type;
    }

    if (storing_type)
    {
        try
        {
            Repository* repository = new Repository("Coats.txt");
            repository->readFromFile();
            CSV_Cart* cart1 = new CSV_Cart();
            HTML_Cart* cart2 = new HTML_Cart();
            Service* service = new Service(repository, cart1);
            if (storing_type == 2)
            {
                service->setCart(cart2);
            }
            
            Validator v;
            UI* ui = new UI(service, v);
            ui->runMenu(storing_type);

            delete ui;
            delete service;
            cart1->getAllProducts().~vector();
            delete cart1;
            cart2->getAllProducts().~vector();
            delete cart2;
            delete repository;

        }

        catch (FileException&)
        {
            std::cout << "Storage file couldn't be opened!";
            return -25;
        }
    }

    return 0;
}
*/

