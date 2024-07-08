#include "Repository.h"
#include <iostream>



Product& Repository::getObjectOnPositionCopy(int position) const
{
	return (Product&)this->objects[position];
}


int Repository::findByLink(std::string link)
{
	auto iterator = find_if(this->objects.begin(), this->objects.end(),
		[link](const auto& object)
		{
			return object.getPhotograph() == link;
		});

	// if a product was found => the iterator points to an actual objectS
	if (iterator != this->objects.end())
	{
		return distance(this->objects.begin(), iterator);
	}

	// if it wasn't found any product with that link
	return -1;
}


//CRUD
int Repository::addObject(const Product& object)
{
	int result;
	if (this->findByLink(object.getPhotograph()) != -1)
	{
		result = -1;
	}
	else
	{
		result = 1;
		this->objects.push_back(object);
		
		this->writeToFile();
	}
	return result;
}


int Repository::removeObject(const Product& object)
{
	auto iterator = find(this->objects.begin(), this->objects.end(), object);

	this->objects.erase(iterator);

	this->writeToFile();
	return 1;
}


int Repository::removeObjectByLink(std::string link)
{
	int position = this->findByLink(link);
	if (position == -1)
	{
		return -1;
	}
	return this->removeObject(this->getObjectOnPosition(position));
}


int Repository::updateObject(std::string link, int size_new, std::string color_new, int price_new, int quantity_new)
{
	int position = this->findByLink(link);

	if (position == -1)
	{
		return -1;
	}
	Product& object = this->getObjectOnPositionCopy(position);
	object.setSize(size_new);
	object.setColor(color_new);
	object.setPrice(price_new);
	object.setQuantity(quantity_new);

	this->writeToFile();

	return 1;
}


void Repository::populate()
{
	Product t1 = Product(36, "Beige", 21275, 100, "https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080");
	this->objects.push_back(t1);
	Product t2 = Product(34, "Pink", 348, 10050, "https://cdn.aboutstatic.com/file/images/6de565f5258f0a18507b84a93fef3363.png?bg=F4F4F5&quality=75&trim=1&height=480&width=360");
	this->objects.push_back(t2);
	Product t3 = Product(36, "Black", 450, 105, "https://www.mohito.com/ro/ro/trench-elegant-cu-curea-3403u-99x?gclid=Cj0KCQjw8qmhBhClARIsANAtbocb5I8uOWTtt7Haou4_9U-s8zXWhV76MYumoJ7ZAFgqOT33O9QEVhgaAtdBEALw_wcB");
	this->objects.push_back(t3);
	Product t4 = Product(36, "Black", 500, 10, "https://www.zalando.ro/mango-palton-clasic-schwarz-m9121u1ad-q11.html?size=M&allophones=0&wmc=SEM400_NB_GO._3625232631_17072920796_137263143538.&opc=2211&mpp=google|v1||pla-293946777986||1011806||g|c||595096751273||pla|M9121U1AD-Q11000M000|293946777986|1|&gclid=Cj0KCQjw8qmhBhClARIsANAtbofZ6JQlAHoIAovZyPmfbc6GuX9BCC1Fpn_Kcy2a2gYYVTLXzaYJJuAaAtnJEALw_wcB");
	this->objects.push_back(t4);
	Product t5 = Product(38, "Black", 389, 156, "https://remixshop.com/ro/womens-clothes/coats?brand_range=MID&product_id=27349176&page_type=pdlp&utm_campaign=dynamic_ads&utm_source=google&utm_medium=cpc&utm_content=shopping_premium&utm_term=product_page&gclid=Cj0KCQjw8qmhBhClARIsANAtboekG0H6L1y-yLkHz21k08C6Q0qyLFBhSVH1niNJPUtFWQyaQmu8-wEaAq0lEALw_wcB");
	this->objects.push_back(t5);
	Product t6 = Product(40, "Black", 247, 105, "https://www.aboutyou.ro/p/only/palton-de-primavara-toamna-line-5570004?vid=42790679&om_channel=PLA&utm_content=ppc&utm_source=google&utm_medium=cpc&utm_campaign=PLA_RO_Mid_AP_Generic_NK_CSS_S24&gclid=Cj0KCQjw8qmhBhClARIsANAtboc60-EHLMlqH5tTAFREBMUyoD1S0f1d-Ljdi-RDK2IbSj-_LedTuhoaAgdsEALw_wcB");
	this->objects.push_back(t6);
	Product t7 = Product(34, "kaki", 555, 1005, "https://cdn.aboutstatic.com/file/images/6820ac993dc4ece219ccaa37f9a92438.jpg?quality=75&height=480&width=360");
	this->objects.push_back(t7);
	Product t8 = Product(36, "Ivory", 160, 16, "https://static.sinsay.com/media/catalog/product/3/1/3149F-01X-001-1-580435_10.jpg");
	this->objects.push_back(t8);
	Product t9 = Product(34, "Ivory", 160, 25, "https://static.sinsay.com/media/catalog/product/3/1/3149F-01X-003-1-585271_10.jpg");
	this->objects.push_back(t9);
	Product t10 = Product(36, "Pink", 115, 234, "https://media.remix.eu/files/41-2022/Damski-shlifer-Bik-Bok-117517578a.jpg");
	this->objects.push_back(t10);
}



// file functions

void Repository::readFromFile()
{
	ifstream file(this->file);

	if (!file.is_open())
	{
		throw FileException("Error! The file can't be opened!");
	}

	Product t;
	while (file >> t)
	{
		this->objects.push_back(t);
	}

	file.close();
}


void Repository::writeToFile()
{
	ofstream file(this->file);

	if (!file.is_open())
	{
		throw FileException("The file could not be opened!");
	}

	for (auto product : this->objects)
	{
		file << product;
	}

	file.close();
}