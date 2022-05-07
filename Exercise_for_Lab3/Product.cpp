#include "Product.h"

Product::Product()
{
	this->SetName(" ");
	this->SetDescription(" ");
	this->SetCost(0);
}

Product::Product(string name, string description, double cost)
{
	this->SetName(name);
	this->SetDescription(description);
	this->SetCost(cost);
}

void Product::SetName(string name)
{
	this->_name = name;
}

void Product::SetDescription(string description)
{
	this->_description = description;
}

void Product::SetCost(double cost)
{
	if (cost < 0)
	{
		throw exception("Cost should be > 0!");
	}
	this->_cost = cost;
}

string Product::GetName()
{
	return this->_name;
}

string Product::GetDescription()
{
	return this->_description;
}

double Product::GetCost()
{
	return this->_cost;
}