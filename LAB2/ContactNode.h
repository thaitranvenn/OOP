#pragma once
#include <string>

using namespace std;

struct ContactNode
{
	string name;//Название контакта
	string number;//string потому, что номера бывают разной длины.
	string description;//Описание контакта
	bool isInBlackist;
};