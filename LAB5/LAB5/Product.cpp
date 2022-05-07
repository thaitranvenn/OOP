#include <iostream>
#include "Product.h"

void Product::SetProduct(string name, double price, CategoryType category)
{
	if (100000 < price < 0)
	{
		throw exception("The price must be between 0 and 100,000!");
	}

	this->_name = name;
	this->_price = price;
	this->_category = category;
}

void Product::GetProduct()
{
	cout << "Product: " << this->_name << endl;
	cout << "Price: " << this->_price << endl;
	cout << "Product category: ";
	switch (this->_category)
	{
	case 1: { cout << "Fruit" << endl; }; break;
	case 2: { cout << "Milk products" << endl; }; break;
	case 3: { cout << "Confectionery" << endl; }; break;
	case 4: { cout << "Meat products" << endl; }; break;
	case 5: { cout << "Beverages" << endl; }; break;
	}
}

void Product::SetPrice(double price)
{
	if (100000 < price < 0)
	{
		throw exception("The price must be between 0 and 100,000!");
	}
	this->_price = price;
}

string Product::GetName()
{
	return this->_name;
}

double Product::GetPrice()
{
	return this->_price;
}

double Product::GetCategory()
{
	return this->_category;
}

Product::Product()
{
}

Product::Product(string name, double price, CategoryType category)
{
	SetProduct(name, price, category);
}
