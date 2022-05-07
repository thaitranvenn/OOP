#pragma once
#include "Product.h"

class Cart
{
private:
	Product* _products;
	int _productsCount;

public:
	Cart();
	Cart(Product* products, int productsCount, string category);

	void SetProducts(Product* products);
	void SetProductsCount(int productsCount);

	Product* GetProducts();
	int GetProductsCount();
	double GetFullCost();
};