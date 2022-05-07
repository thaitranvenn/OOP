#pragma once
#include <iostream>
#include "RectangleNode.h"
#include "functions.h"

using namespace std;

void ShowRectangleNode(RectangleNode* temp)
{
	cout << "\nColor: " << temp->color;
	cout << "\nRectangle size: " << temp->length << "x" << temp->width << endl;
};

void DemoRectangle()
{
	RectangleNode* temp = new RectangleNode;
	temp->color = "Red";
	do
	{
		temp->length = rand() % 20;
		temp->width = rand() % 20;
	} while ((temp->length == 0) || (temp->width == 0));
	ShowRectangleNode(temp);
	delete temp;
}

RectangleNode* CinRectangleNode()
{
	RectangleNode* temp = new RectangleNode;
	cout << "\nEnter color: ";
	cin >> temp->color;
	cout << "\nEnter length: ";
	temp->length = CheckInt();
	cout << "\nEnter width: ";
	temp->width = CheckInt();
	return temp;
}

void DemoRectangleAdress()
{
	RectangleNode temp;
	temp.color = "red";
	do {
		temp.length = rand() % 20;
		temp.width = rand() % 20;
	} while ((temp.width == 0) || (temp.length == 0));
	ShowRectangleNode(&temp);
	RectangleNode* NewTemp = &temp;
	cout << "\nAddress NewTemp: " << NewTemp;
	cout << "\nAddress Temp: " << &temp;
	cout << "\nValue NewTemp: " << endl;
	ShowRectangleNode(NewTemp);
	cout << endl;
	NewTemp->color = "Pink";
	do
	{
		NewTemp->length = rand() % 20;
		NewTemp->width = rand() % 20;
	} while ((NewTemp->width == 0) || (NewTemp->length == 0));
	ShowRectangleNode(&temp);
	cout << "\nTemp: " << &temp;
	cout << "\nNewTemp: " << NewTemp;
};

void WriteRectangle(RectangleNode& rectangle)
{
	cout << "\nRectangle size: " << rectangle.length << "x" << rectangle.width << endl;
};

void ReadRectangle(RectangleNode& rectangle)
{
	cout << "\nEnter length: ";
	rectangle.length = CheckInt();
	cout << "\nEnter width: ";
	rectangle.width = CheckInt();
}

void DemoReadAndWriteRectangles()
{
	int count;
	do
	{
		cout << "Enter number of rectangles: ";
		count = CheckInt();
		cout << endl;
	} while (count <= 0);
	RectangleNode* rectangle = new RectangleNode[count];
	for (int i = 0; i < count; i++)
	{
		ReadRectangle(rectangle[i]);
	}
	for (int i = 0; i < count; i++)
	{
		WriteRectangle(rectangle[i]);
	}
};

void Exchange(RectangleNode& rectangle1, RectangleNode& rectangle2)
{
	RectangleNode rectangle;
	rectangle.length = rectangle1.length;
	rectangle.width = rectangle1.width;
	rectangle1.length = rectangle2.length;
	rectangle1.width = rectangle2.width;
	rectangle2.length = rectangle.length;
	rectangle2.width = rectangle.width;
};

void FindRectangle(RectangleNode* rectangles, int count)
{
	int max = rectangles[0].length;
	for (int i = 0; i < count; i++)
	{
		if (max < rectangles[i].length)
		{
			max = rectangles[i].length;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (rectangles[i].length == max)
		{
			cout << "\nRectangle with the biggest length: " << max << "x" << rectangles[i].width;
			break;
		}
	}
	cout << endl;
}

void FindMaxRectangle(RectangleNode* rectangles, int count)
{
	int max = rectangles[0].length * rectangles[0].width;
	for (int i = 0; i < count; i++)
	{
		if (max < rectangles[i].length * rectangles[i].width)
		{
			max = rectangles[i].length * rectangles[i].width;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (rectangles[i].length * rectangles[i].width == max)
		{
			cout << "\nRectangle with the biggest area: " << rectangles[i].length << "x" << rectangles[i].width << endl;
			break;
		}
	}
}

RectangleNode* MakeRectangle(const char* color, int length, int width)
{
	RectangleNode* temp = new RectangleNode;
	temp->color = color;
	temp->length = length;
	temp->width = width;
	return temp;
}

RectangleNode* CopyRectangle(RectangleNode* Rectangle)
{
	RectangleNode* temp = new RectangleNode;
	temp->color = Rectangle->color;
	temp->length = Rectangle->length;
	temp->width = Rectangle->width;
	return temp;
}