#include"Rectangle.h"
#define  RECTANGLES_COUNT 7

Rectangle::Rectangle(double length, double width, Point center)
{
	this->SetLength(length);
	this->SetWidth(width);
	this->SetCenter(center);
}

Rectangle::Rectangle()
{
	this->SetLength(0);
	this->SetWidth(0);
	this->SetCenter(Point());
}

double Rectangle::GetLength()
{
	return this->_length;
}

double Rectangle::GetWidth()
{
	return this->_width;
}

Point Rectangle::GetCenter()
{
	return this->_center;
}

void Rectangle::SetLength(double length)
{
	if (length < 0)
	{
		throw exception("Length cannot be < 0.");
	}
	this->_length = length;
}

void Rectangle::SetWidth(double width)
{
	if (width < 0)
	{
		throw exception("Width cannot be < 0.");
	}
	this->_width = width;
}

void Rectangle::SetCenter(Point point)
{
	this->_center = point;
}

void DemoRectangleWithPoint()
{
	Rectangle* rectangles = new Rectangle[RECTANGLES_COUNT];
	rectangles[0] = Rectangle(3, 4, Point(3, 4));
	rectangles[1] = Rectangle(4, 5, Point(4, 5));
	rectangles[2] = Rectangle(5, 6, Point(5, 6));
	rectangles[3] = Rectangle(6, 7, Point(6, 7));
	rectangles[4] = Rectangle(7, 8, Point(7, 8));
	rectangles[5] = Rectangle(8, 9, Point(8, 9));
	rectangles[6] = Rectangle(9, 10, Point(9, 10));


	double sumX = 0, sumY = 0;
	for (int i = 0; i < RECTANGLES_COUNT; i++)
	{
		cout << "X = " << rectangles[i].GetCenter().GetX() << ";\t"
			<< "Y = " << rectangles[i].GetCenter().GetY() << ";\t"
			<< "Length = " << rectangles[i].GetLength() << ";\t"
			<< "Width = " << rectangles[i].GetWidth() << "." << endl;

		sumX += rectangles[i].GetCenter().GetX();
		sumY += rectangles[i].GetCenter().GetY();
	}
	cout << "\nX = " << sumX / RECTANGLES_COUNT << ";\t"
		<< "Y = " << sumY / RECTANGLES_COUNT;

	delete[] rectangles;
}