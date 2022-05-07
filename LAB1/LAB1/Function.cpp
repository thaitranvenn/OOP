#include<iostream>
#include"Header.h"

using namespace std;

double Random(double min, double max)
{
    return (double)(rand()) / RAND_MAX * (max - min) + min;
}

int CheckInt()
{
    int element;
    bool correct = false;
    while (!correct)
    {
        cin >> element;
        if (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n');
            {
                cout << "Enter a valid value: " << endl;
                correct = false;
            }
        }
        else
        {
            return element;
        }
    }
}

void Breakpoints()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        // Поставьте условную точку останова здесь
        sum += add * i;
        if (i % 3 == 0)
        {
            add *= 1.1;
        }
        else
        {
            add /= 3.0;
        }
    }
    cout << "Total sum is " << sum << endl;
}

void RoundToTens(int& value)
{
    if (value % 10 < 5)
    {
        value = value / 10;
        value = value * 10;
    }
    else
    {
        value = value / 10;
        value++;
        value = value * 10;
    }
}

double GetPower(double base, int exponent)
{
    double temp = 1;
    if (exponent == 0)
    {
        return temp;
    }
    for (int i = 1; i <= exponent; i++)
    {
        temp = temp * base;
    }
    return temp;
}

void DemoGetPower(double base, int exponent)
{
    cout << base << "^" << exponent << " = " << GetPower(base, exponent);
}

void Foo(double a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}
void SecondFoo(double& a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}
void ThirdFoo(double* a)
{
    cout << "Address in pointer: " << a << endl;
    cout << "Address of pointer: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;

    *a = 15.0;
    cout << "New value in pointer address: " << *a << endl;
}

void DoubleSorting(double* array)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 9; j++)
        {
            if (array[j + 1] < array[i])
            {
                double temp = array[i];
                array[i] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int* MakeRandomArray(int arraySize)
{
    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 100;
    }
    return array;
}

int* ReadArray(int count)
{
    int* values = new int[count];
    for (int i = 0; i < count; i++)
    {
        cin >> values[i];
    }
    return values;
}

int CountPositiveValues(int* values, int count)
{
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        if (values[i] > 0)
        {
            result++;
        }
    }
    return result;
}

int GetIndexOfMax(double* array)
{
    int index = 0;
    for (int i = 0; i < 8; i++)
    {
        if (array[i] > array[index])
        {
            index = i;
        }
    }
    return index;
}
