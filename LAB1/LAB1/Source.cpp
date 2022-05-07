#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    while (true)
    {
        system("cls");
        cout << "To exit the program, enter 0.\n";
        cout << "\t\t\t\t\t\tProgram menu:\n\n\n";
        cout << "|1) Breakpoints.                                    |12) Passing to a function by reference.                                 \n";
        cout << "|2) Array Sort.                                     |13) Pointers.                                                           \n";
        cout << "|3) Search for values bigger than entered.          |14) Passing a pointer to a function.                                    \n";
        cout << "|4) Search all letters in an array.                 |15) Dynamic array (double) and its initialization.                      \n";
        cout << "|5) Exponentiation.                                 |16) Dynamic array (bool) and its initialization.                        \n";
        cout << "|6) Function use DemoGetPower().                    |17) Dynamic array (char) and its initialization.                        \n";
        cout << "|7) Rounding.                                       |18) Sorting a dynamic array (double).                                   \n";
        cout << "|8) Variable Addresses.                             |19) Search for the index of the specified array element (int).          \n";
        cout << "|9) Array Cell Addresses.                           |20) Output letters of a dynamic array (char).                           \n";
        cout << "|10) References.                                    |21) Set random value to dynamic array.                                  \n";
        cout << "|11) Passing to a function by value.                |22) Corrected version of the search for the number of positive elements.\n";
        cout << "|23) Output index of the biggest element.\n";
        int choice = CheckInt();
        switch (choice)
        {
        case 0:
        {
            cout << "Exiting the program ...\n";
            return 0;
        }
        case 1:
        {
            Breakpoints();
            system("pause");
            break;
        }
        case 2:
        {
            int arr[10];
            for (int i = 0; i < 10; i++)
            {
                arr[i] = rand() % 150;
                cout << arr[i] << " ";
            }
            cout << "\nSorted option:\n";
            for (int i = 0; i < 10; i++)
            {
                for (int j = i; j < 9; j++)
                {
                    if (arr[j + 1] < arr[i])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                cout << arr[i] << " ";
            }
            cout << endl;
            system("pause");
            break;
        }
        case 3:
        {
            double DoubleArr[12];
            for (int i = 0; i < 12; i++)
            {
                DoubleArr[i] = Random(-1.5, 1500.5);
                cout << DoubleArr[i] << " ";
            }
            int sum = 0;
            cout << "\nEntered value:\n";
            double searchingValue;
            cin >> searchingValue;
            for (int i = 0; i < 12; i++)
            {
                if (DoubleArr[i] >= searchingValue)
                {
                    sum++;
                }
            }
            cout << "Elements bigger than " << searchingValue << ": " << sum;
            cout << endl;
            system("pause");
            break;
        }
        case 4:
        {
            char charArr[8];
            for (int i = 0; i < 8; i++)
            {
                cout << "Enter element N" << i + 1 << ":";
                cin >> charArr[i];
            }
            cout << "All letters in a character array: \n";
            for (int i = 0; i < 8; i++)
            {
                if (isalpha(charArr[i]))
                {
                    cout << charArr[i] << "\t";
                }
            }
            cout << endl;
            system("pause");
            break;
        }
        case 5:
        {
            cout << "Enter the number of operations:\n";
            int number = CheckInt();
            while (number < 0)
            {
                cout << "Enter the number of operations:\n";
                int number = CheckInt();
            }
            for (int i = 0; i < number; i++)
            {
                cout << "Enter base value:\n";;
                double base;
                cin >> base;
                cout << "Enter exponent value:\n";
                int exponent = CheckInt();
                cout << base << "^" << exponent << " = " << GetPower(base, exponent) << endl;
            }
            cout << endl;
            system("pause");
            break;
        }
        case 6:
        {
            cout << "Enter the number of operations:\n";
            int number = CheckInt();
            while (number < 0)
            {
                cout << "Enter the number of operations:\n";
                int number = CheckInt();
            }
            for (int i = 0; i < number; i++)
            {
                cout << "\nEnter value base:\n";;
                double base;
                cin >> base;
                cout << "Enter exponent value:\n";
                int exponent = CheckInt();
                cout << "Function use DemoGetPower().\n";
                DemoGetPower(base, exponent);
            }
            cout << endl;
            system("pause");
            break;
        }
        case 7:
        {
            cout << "Enter the number of operations:\n";
            int number = CheckInt();
            while (number < 0)
            {
                cout << "Enter the number of operations:\n";
                int number = CheckInt();
            }
            for (int i = 0; i < number; i++)
            {
                cout << "Enter value:\n";
                int value = CheckInt();
                cout << "Value " << value;
                RoundToTens(value);
                cout << " Rounded to " << value << ";\n";
            }
            cout << endl;
            system("pause");
            break;
        }
        case 8:
        {
            cout << "Each time the program starts, the addresses of the variables will be different.\n";
            int a = 5;
            int b = 10;
            cout << "Variable address a: " << &a << endl;
            cout << "Variable address b: " << &b << endl;
            double c = 13.5;
            cout << "Variable address c: " << &c << endl;
            bool d = true;
            cout << "Variable address d: " << &d << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 9:
        {
            int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
            cout << "The size of one cell type int: " << sizeof(int) << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << "Variable address a[" << i << "]: " << &a[i] << endl;
            }
            cout << endl;
            cout << "The size of one cell type double: " << sizeof(double) << endl;
            double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2
            };
            for (int i = 0; i < 10; i++)
            {
                cout << "Variable address b[" << i << "]: " << &b[i] << endl;
            }
            cout << endl;
            system("pause");
            break;
        }
        case 10:
        {
            cout << "Link the addresses of the variables a & b.\n";
            int a = 5;
            int& b = a;
            cout << "Variable address a: " << &a << endl;
            cout << "Variable address b: " << &b << endl;
            cout << endl;
            cout << "\nSet variable b to 10.\n";
            b = 10;
            cout << "Variable value a: " << a << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 11:
        {
            double a = 10.0;
            cout << "Address a in function main(): " << &a << endl;
            cout << "The value of a in the function main(): " << a << endl;
            cout << endl;
            Foo(a);
            cout << endl;
            cout << "The value of a in the main () function after";
            cout << " The functions Foo(a): " << a << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 12:
        {
            double a = 10.0;
            cout << "Address a in function main(): " << &a << endl;
            cout << "The value of a in the function main(): " << a << endl;
            cout << endl;
            SecondFoo(a);
            cout << endl;
            cout << "The value of a in the main () function after";
            cout << "The functions SecondFoo(a) : " << a << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 13:
        {
            int a = 5;
            int* pointer = &a;
            cout << "Variable address a: " << &a << endl;
            cout << "Address in pointer: " << pointer << endl;
            cout << "Variable address pointer: " << &pointer << endl;
            cout << endl;
            cout << "*pointer = 10;" << endl;
            *pointer = 10;
            cout << "Value in variable a: " << a << endl;
            cout << "Value from address pointer: " << *pointer << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 14:
        {
            double value = 5.0;
            double* pointer = &value;
            cout << "Variable address value in main(): " << &value << endl;
            cout << "Address in Variable pointer in main(): " << pointer << endl;
            cout << "Variable address pointer in main(): " << &pointer << endl;
            cout << "The value of the variable a in main(): " << value << endl;
            cout << endl;
            ThirdFoo(pointer);
            cout << endl;
            cout << "The value of the variable a in main(): " << value << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 15:
        {
            double* doubleArray = new double[8];
            cout << "Array of real numbers:\n";
            for (int i = 0; i < 8; i++)
            {
                doubleArray[i] = Random(-10, 10);
                cout << doubleArray[i] << " ";
            }
            delete[] doubleArray;
            cout << endl;
            system("pause");
            break;
        }
        case 16:
        {
            bool* boolArray = new bool[8];
            cout << "Array of boolean variables:\n";
            for (int i = 0; i < 8; i++)
            {
                boolArray[i] = false;
                if (rand() % 2 == 1)
                {
                    boolArray[i] = true;
                    cout << "True ";
                }
                else
                {
                    boolArray[i] = false;
                    cout << "False ";
                }
            }
            cout << endl;
            delete[] boolArray;
            system("pause");
            break;
        }
        case 17:
        {
            cout << "Enter the capacity of the character array:\n";
            int number = CheckInt();
            while (number < 0)
            {
                cout << "Enter the capacity of the character array:\n";
                int number = CheckInt();
            }
            char* charArray = new char[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter a value for charArray[" << i << "] = ";
                cin >> charArray[i];
                cout << endl;
            }
            cout << "Enter array values charArray:\n";
            for (int i = 0; i < number; i++)
            {
                cout << charArray[i] << '\t';
            }
            cout << endl;
            delete[] charArray;
            system("pause");
            break;
        }
        case 18:
        {
            double* doubleArray = new double[10];
            cout << "Array of double: \n";
            for (int i = 0; i < 10; i++)
            {
                doubleArray[i] = Random(-10, 10);
                cout << doubleArray[i] << " ";
            }
            DoubleSorting(doubleArray);
            cout << "\nSorted array of double: \n";
            for (int i = 0; i < 10; i++)
            {
                cout << doubleArray[i] << " ";
            }
            cout << endl;
            delete[] doubleArray;
            system("pause");
            break;
        }
        case 19:
        {
            int* array = new int[10];
            for (int i = 0; i < 10; i++)
            {
                cout << "Index of number: " << i << " Enter number: ";
                array[i] = CheckInt();
            }
            cout << endl;
            cout << "Enter searching value: " << endl;
            int searchingElement = CheckInt();
            bool isTrue = false;
            for (int i = 0; i < 10; i++)
            {
                if (array[i] == searchingElement)
                {
                    isTrue = true;
                    cout << "Index of searching value " << searchingElement << " is: " << i << endl;
                }
            }
            if (!isTrue)
            {
                cout << "Item index not found.\n";
            }
            cout << endl;
            delete[] array;
            system("pause");
            break;
        }
        case 20:
        {
            char* charArray = new char[10];
            for (int i = 0; i < 10; i++)
            {
                cout << "Enter symbol N" << i + 1 << ":";
                cin >> charArray[i];
            }
            for (int i = 0; i < 10; i++)
            {
                if (isalpha(charArray[i]))
                {
                    cout << charArray[i] << " ";
                }
            }
            cout << endl;
            delete[] charArray;
            system("pause");
            break;
        }
        case 21:
        {
            cout << "Enter the number of operations:\n";
            int number = CheckInt();
            while (number < 0)
            {
                cout << "Enter the number of operations:\n";
                int number = CheckInt();
            }
            int** randArray = new int* [number];
            // Запомнить ёмкость динамического массива
            int* capacity = new int[number];
            for (int i = 0; i < number; i++)
            {
                cout << "\nEnter the capacity of the array N" << i + 1 << ":\n";
                capacity[i] = CheckInt();
                while (capacity[i] < 0)
                {
                    cout << "\nEnter the capacity of the array N" << i + 1 << ":\n";
                    capacity[i] = CheckInt();
                }
                randArray[i] = MakeRandomArray(capacity[i]);
            }
            for (int i = 0; i < number; i++)
            {
                cout << "Array N" << i + 1 << endl;
                for (int j = 0; j < capacity[i]; j++)
                {
                    cout << randArray[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            for (int i = 0; i < number; i++)
            {
                delete[] randArray[i];
            }
            delete[] capacity;
            delete[] randArray;
            system("pause");
            break;
        }
        case 22:
        {
            int count = 15;
            int* values = ReadArray(count);
            cout << "Count is: " << CountPositiveValues(values, count) << endl;
            // Без этой строки будет утечка памяти.
            delete[] values;
            count = 20;
            values = ReadArray(count);
            cout << "Count is: " << CountPositiveValues(values, count) << endl;
            delete[] values;
            system("pause");
            break;
        }
        case 23:
        {
            double* doubleArray = new double[8];
            cout << "Array of real numbers:\n";
            for (int i = 0; i < 8; i++)
            {
                doubleArray[i] = Random(-20, 20);
                cout << "Index:" << i << "\tElement: " << doubleArray[i] << endl;
            }
            cout << "Index of the biggest element: " << GetIndexOfMax(doubleArray) << endl;
            delete[] doubleArray;
            cout << endl;
            system("pause");
            break;
        }
        }
    }
}