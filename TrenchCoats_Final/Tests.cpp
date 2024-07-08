//#include "Tests.h"
//#include <assert.h>
//#include <iostream>
//
//
//
//void test_addService()
//{
//	Repository* repository = new Repository("Coats.txt");
//	//repository->populate();
//	ShoppingCart* cart = new ShoppingCart();
//	Service* service = new Service(repository, cart);
//
//	assert(service->findInRepoService("dgsdg") == -1);
//	assert(service->addService(Product(36, "Beige", 21275, 100, "dgsdg")) == 1);
//	assert(service->addService(Product(36, "Beige", 21275, 100, "https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080")) == -1);
//	assert(service->getObjectFromRepository(10).getColor() == "Beige");
//	assert(service->getRepoSize() == 11);
//
//	cart->getAllProducts().~vector();
//	delete service;
//	delete cart;
//	delete repository;
//}
//
//
//void test_removeService()
//{
//	Repository* repository = new Repository("Coats.txt");
//	repository->populate();
//	ShoppingCart* cart = new ShoppingCart();
//	Service* service = new Service(repository, cart);
//
//	assert(service->getRepo()->getRepositorySize() == 10);
//	assert(service->removeService("https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080") == 1);
//	assert(service->removeService("https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080") == -1);
//	assert(repository->getAllObjectsFromRepo().size() == 9);
//
//	cart->getAllProducts().~vector();
//	delete service;
//	delete cart;
//	delete repository;
//}
//
//
//void test_updateService()
//{
//	Repository* repository = new Repository("Coats.txt");
//	repository->populate();
//	ShoppingCart* cart = new ShoppingCart();
//	Service* service = new Service(repository, cart);
//
//	assert(service->addService(Product(36, "Beige", 21275, 100, "dgsdg")) == 1);
//	assert(service->updateService("dgsdg", 34, "lila", 123, 123) == 1);
//	assert(service->updateService("notexist", 34, "lila", 356, 355) == -1);
//
//	cart->getAllProducts().~vector();
//	delete service;
//	delete cart;
//	delete repository;
//}
//
//
//void test_getBySize()
//{
//	Repository* repository = new Repository("Coats.txt");
//	repository->populate();
//	ShoppingCart* cart = new ShoppingCart();
//	Service* service = new Service(repository, cart);
//
//	assert(cart->isEmpty() != 0);
//	assert(cart->deleteByLink("fsdf") == 0);
//	assert(service->getBySize(40)->getCartLength() == 1);
//	assert(service->getBySize(0)->getCartLength() == 10);
//	//assert(cart->next() == 1);
//
//	cart->getAllProducts().~vector();
//	delete cart;
//	delete service;
//	delete repository;
//}
//
//
//void test_ShoppingCart()
//{
//	Repository* repository = new Repository("Coats.txt");
//	repository->populate();
//	ShoppingCart* cart = new ShoppingCart();
//	Service* service = new Service(repository, cart);
//
//	assert(cart->isEmpty() != 0);
//	assert(cart->addProductToCart(repository->getProductsFromRepo()[0]) == 1);
//	assert(cart->addProductToCart(repository->getProductsFromRepo()[1]) == 1);
//	assert(cart->getCurrentIndex() == 0);
//	assert(cart->getCurrentProduct().getColor() == "Beige");
//	assert(cart->next() == 1);
//	assert(cart->getCurrentIndex() == 1);
//	assert(cart->next() == 1);
//	assert(cart->next() == 1);
//
//	cart->addProductToCart(Product(36, "Beige", 21275, 100, "dgsdg"));
//	assert(cart->getPosition("dgsdg") == 2);
//	assert(cart->getPosition("no") == -1);
//
//	assert(service->getBySize(40)->getCartLength() == 1);
//	assert(service->getBySize(0)->getCartLength() == 10);
//
//
//	cart->getAllProducts().~vector();
//	delete cart;
//	delete service;
//	delete repository;
//}
//
//
//void allTests()
//{
//	test_addService();
//	test_removeService();
//	test_updateService();
//	test_getBySize();
//	test_ShoppingCart();
//}
//
