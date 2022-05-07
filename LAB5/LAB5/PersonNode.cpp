#include "PersonNode.h"
#include <iostream>
#include "CheckInt.h"

string PersonNode::getName()//На 5.1.4. Создается, но не передаются данные и берётся стандартный конструктор.
{
	return this->name;
};

string PersonNode::getSurname()
{
	return this->surname;
};

string PersonNode::getMiddleName()
{
	return this->middlename;
};

void PersonNode::setName()
{
	cout << "Enter name: ";
	this->name = setString();
};

void PersonNode::setSurname()
{
	cout << "Enter surname: ";
	this->name = setString();
};

void PersonNode::setMiddleName()
{
	cout << "Enter middle name: ";
	this->name = setString();
};

PersonNode::PersonNode()
{
	this->setName();
	this->setSurname();
	this->setMiddleName();
};

PersonNode::PersonNode(string name, string surename, string middlename)
{
	this->name = name;
	this->surname = surename;
	this->middlename = middlename;
};

void ShowName(PersonNode* person)
{
	cout << endl << person->getSurname() << " " << person->getName() << " " << person->getMiddleName() << endl;
};