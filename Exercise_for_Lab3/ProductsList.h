#pragma once
#include "Product.h"

class ProductsList
{
private:
	Product* _products;
	int _productsCount;
	string _category;

public:
	ProductsList();
	ProductsList(Product* products, int productsCount, string category);

	void SetProducts(Product* products);
	void SetProductsCount(int productsCount);
	void SetCategory(string category);

	Product* GetProducts();
	int GetProductsCount();
	string GetCategory();
};