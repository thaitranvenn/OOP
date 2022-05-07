#include "ProductsList.h"

ProductsList::ProductsList()
{
	this->SetProducts(nullptr);
	this->SetProductsCount(0);
	this->SetCategory(" ");
}

ProductsList::ProductsList(Product* products, int productsCount, string category)
{
	this->SetProducts(products);
	this->SetProductsCount(productsCount);
	this->SetCategory(category);
}

void ProductsList::SetProducts(Product* products)
{
	this->_products = products;
}

void ProductsList::SetProductsCount(int productsCount)
{
	if (productsCount < 0)
	{
		throw exception("ProductsCount should be > 0");
	}
	this->_productsCount = productsCount;
}

void ProductsList::SetCategory(string category)
{
	this->_category = category;
}

Product* ProductsList::GetProducts()
{
	return this->_products;
}

int ProductsList::GetProductsCount()
{
	return this->_productsCount;
}

string ProductsList::GetCategory()
{
	return this->_category;
}