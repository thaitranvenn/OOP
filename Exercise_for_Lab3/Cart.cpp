#include "Cart.h"

Cart::Cart()
{
	this->SetProducts(nullptr);
	this->SetProductsCount(0);
}

Cart::Cart(Product* products, int productsCount, string category)
{
	this->SetProducts(products);
	this->SetProductsCount(productsCount);
}

void Cart::SetProducts(Product* products)
{
	this->_products = products;
}

void Cart::SetProductsCount(int productsCount)
{
	if (productsCount < 0)
	{
		throw exception("ProductCounts should be > 0");
	}
	this->_productsCount = productsCount;
}

Product* Cart::GetProducts()
{
	return this->_products;
}

int Cart::GetProductsCount()
{
	return this->_productsCount;
}

double Cart::GetFullCost()
{
	double sum = 0;
	for (int i = 0; i < this->GetProductsCount(); i++)
	{
		sum += this->GetProducts()[i].GetCost();
	}
	return sum;
}