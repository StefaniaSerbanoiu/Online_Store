#include "FileBasedCart.h"


class CSV_Cart : public FileBasedCart
{
public:
	void writeToFile() override;
	void display() const override;
};