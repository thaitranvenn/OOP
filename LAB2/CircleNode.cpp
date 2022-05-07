#pragma once
#include <iostream>
#include "CircleNode.h"
#include "functions.h"

using namespace std;

void ShowCircle(Circle* circle)
{
    cout << "X = " << circle->X << "; Y = " << circle->Y << "; Radius = " << circle->Radius << "; Color = " << circle->Color << ";\n";
};

void DemoCircle()
{
    Circle* circle1 = new Circle();
    circle1->X = 3.0;
    circle1->Y = 5.0;
    circle1->Radius = 6.5;
    circle1->Color = "Red";

    Circle* circle2 = new Circle();
    circle2->X = 4.0;
    circle2->Y = -5.0;
    circle2->Radius = 7.0;
    circle2->Color = "Pink";

    Circle* circle3 = new Circle();
    circle3->X = 0;
    circle3->Y = 0;
    circle3->Radius = 5.0;
    circle3->Color = "Blue";

    Circle* copiedCircle1 = new Circle();
    copiedCircle1->X = circle1->X;
    copiedCircle1->Y = circle1->Y;
    copiedCircle1->Radius = circle1->Radius;
    copiedCircle1->Color = circle1->Color;


    Circle* copiedCircle2 = new Circle();
    copiedCircle2->X = circle2->X;
    copiedCircle2->Y = circle2->Y;
    copiedCircle2->Radius = circle2->Radius;
    copiedCircle2->Color = circle2->Color;

    Circle* copiedCircle3 = new Circle();
    copiedCircle3->X = circle3->X;
    copiedCircle3->Y = circle3->Y;
    copiedCircle3->Radius = circle3->Radius;
    copiedCircle3->Color = circle3->Color;

    cout << "\nCircle: " << endl;
    ShowCircle(circle1);
    ShowCircle(circle2);
    ShowCircle(circle3);
    ShowCircle(copiedCircle1);
    ShowCircle(copiedCircle2);
    ShowCircle(copiedCircle3);
};

Circle* MakeCircle(double X, double Y, double Radius, const char* Color)
{
    Circle* temp = new Circle;
    temp->X = X;
    temp->Y = Y;
    temp->Radius = Radius;
    temp->Color = Color;
    return temp;
};

void DemoCircleWithMakeAndCopy()
{
    Circle* circle1 = MakeCircle(3.0, 5.0, 6.5, "Red");
    Circle* circle2 = MakeCircle(4.0, -5.5, 7.0, "Pink");
    Circle* circle3 = MakeCircle(0, 0, 5.0, "Blue");
    Circle* copiedCircle1 = CopyCircle(circle1);
    Circle* copiedCircle2 = CopyCircle(circle2);
    Circle* copiedCircle3 = CopyCircle(circle3);
    cout << "\nCircle: " << endl;
    ShowCircle(circle1);
    ShowCircle(circle2);
    ShowCircle(circle3);
    ShowCircle(copiedCircle1);
    ShowCircle(copiedCircle2);
    ShowCircle(copiedCircle3);
};

Circle* CopyCircle(Circle* circle)
{
    Circle* temp = new Circle;
    temp->X = circle->X;
    temp->Y = circle->Y;
    temp->Radius = circle->Radius;
    temp->Color = circle->Color;
    return temp;
}