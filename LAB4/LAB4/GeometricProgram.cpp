#include "GeometricProgram.h"

void GeometricProgram::DemoRing()
{
	bool isCollision = false;
	RingNode** Rings = nullptr;
	int count = 3;
	do
	{
		Rings = new RingNode * [count];
		for (int i = 0; i < count; i++)
		{
			Rings[i] = new RingNode;
		}
		cout << "Rings created: " << RingNode::GetAllRingsCount() << ".\n";
		count = RingNode::GetAllRingsCount();
		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				isCollision = CollisionManager::IsCollision(Rings[i], Rings[j]);
				if (isCollision)
				{
					break;
				}
			}
			if (isCollision)
			{
				break;
			}
		}
		if (isCollision)
		{
			cout << "Some rings intersect!\nEnter data again!\n";
			delete[] Rings;
		}
	} while (isCollision);
	cout << "Number of rings before the constructor is called: " << RingNode::GetAllRingsCount() << endl;
	system("pause");
	RingNode* Ring = new RingNode(10.0, 5.0, 25.0, 25.0);
	cout << "Number of rings after constructor call: " << RingNode::GetAllRingsCount() << endl;
	system("pause");
	delete Ring;
	cout << "Number of rings after destructor call: " << RingNode::GetAllRingsCount() << endl;
	delete[] Rings;
};


void GeometricProgram::DemoCollision()
{
	RectangleNode Rect1 = RectangleNode(PointNode(0, 0), 5, 10);
	RectangleNode Rect2 = RectangleNode(PointNode(2, 2), 5, 10);
	switch (CollisionManager::IsCollision(Rect1, Rect2))
	{
	case true:
	{
		cout << "Rectangles intersect" << endl;
		break;
	}
	case false:
	{
		cout << "Rectangles do not intersect" << endl;
		break;
	}
	}
	RingNode ring1 = RingNode(5, 1, 0, 0);
	RingNode ring2 = RingNode(4, 1, 2, 2);
	switch (CollisionManager::IsCollision(ring1, ring2))
	{
	case true:
	{
		cout << "Rings intersect" << endl;
		break;
	}
	case false:
	{
		cout << "Rings do not intersect" << endl;
		break;
	}
	}
};