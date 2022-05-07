#include "DiscountBase.h"
#include <iostream>

using namespace std;

void DiscountBase::SetCategory(CategoryType categoty)
{
	_category = categoty;
}

CategoryType DiscountBase::GetCategory()
{
	return _category;
}

DiscountBase::DiscountBase(CategoryType category)
{
	SetCategory(category);
}

void ShowCheckWithDiscount(DiscountBase* discount, Product* products, int productsCount)
{
	double allPrice = 0;
	for (int i = 0; i < productsCount; i++)
	{
		allPrice = allPrice + products[i].GetPrice();
	}

	for (int i = 0; i < productsCount; i++)
	{
		cout << "Old item price " << products[i].GetName() << ": " << products[i].GetPrice() << endl;
		products[i].SetPrice(discount->Calculate(&products[i]));
		cout << "Price when discount is applied: " << products[i].GetPrice() << endl;
	}

	double allPriceWithDiscount = 0;
	for (int i = 0; i < productsCount; i++)
	{
		allPriceWithDiscount = allPriceWithDiscount + products[i].GetPrice();
	}
	cout << "The price of the entire list of goods without discount: " << allPrice << endl;
	cout << "The price of the entire list of goods, taking into account the discount: " << allPriceWithDiscount << endl;
	cout << "The discount was: " << allPrice - allPriceWithDiscount << endl;
}