#pragma once
#include <string>

using namespace std;

class PersonNode
{
private:
	string name;
	string surname;
	string middlename;
public:
	string  getName();
	string  getSurname();
	string  getMiddleName();
	void  setName();
	void  setSurname();
	void  setMiddleName();
	PersonNode();
	PersonNode(string name, string surename, string middlename);
};

void ShowName(PersonNode* person);