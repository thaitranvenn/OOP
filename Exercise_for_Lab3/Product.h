#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Product
{
private:
	string _name;
	string _description;
	double _cost;

public:
	Product();
	Product(string name, string description, double cost);

	void SetName(string name);
	void SetDescription(string description);
	void SetCost(double cost);

	string GetName();
	string GetDescription();
	double GetCost();
};