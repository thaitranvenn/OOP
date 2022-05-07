#include "StudentNode.h"
#include <iostream>
#include "CheckInt.h"

string StudentNode::getNumber()
{
	return this->number;
};

int StudentNode::getYear()
{
	return this->year;
};

void StudentNode::setYear()
{
	cout << "Enter year of admission: ";
	this->year = CheckInt();
	cout << endl;
	this->checkYear();
};

bool StudentNode::checkYear()
{
	try
	{
		if (0 < this->year > 2020)
		{
			throw(exception("The year must be in the range [0;2022]\n"));
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	return true;
};

void StudentNode::setNumber()
{
	cout << "Score book number: ";
	this->number = setString();
};

StudentNode::StudentNode(string name, string surename, string patronymic, string number, int year) : PersonNode(name, surename, patronymic)
{
	this->number = number;
	this->year = year;
};

StudentNode::StudentNode() :PersonNode()
{
	this->setNumber();
	this->setYear();
};