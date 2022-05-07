﻿#include <iostream>
#include "CertificateDiscount.h"

void CertificateDiscount::SetAmount(double amount)
{
	if (0 > amount > 10000)
	{
		throw exception("The size of the certificate must be between 0 and 10,000!");
	}
	this->_amount = amount;
}

double CertificateDiscount::GetAmount()
{
	return this->_amount;
}

CertificateDiscount::CertificateDiscount(double amount, CategoryType category) : DiscountBase(category)
{
	SetAmount(amount);
}

double CertificateDiscount::Calculate(Product* product)
{
	if (product->GetCategory() == this->GetCategory())
	{
		if (this->_amount >= product->GetPrice())
		{
			this->_amount = this->_amount - product->GetPrice();
			cout << "Remaining amount of the certificate " << this->_amount << endl;
			return 0.0;
		}
		if (this->_amount < product->GetPrice())
		{
			double newPrice = product->GetPrice() - this->_amount;
			this->_amount = 0;
			cout << "Remaining amount of the certificate " << this->_amount << endl;
			return newPrice;
		}
	}
	else if (product->GetCategory() != this->GetCategory())
	{
		return product->GetPrice();
	}
	return product->GetPrice();
}