﻿#pragma once
double Random(double min, double max);
int CheckInt(); // Проверка введённого значения на тип Int
void Breakpoints();
void RoundToTens(int& value);
double GetPower(double base, int exponent);
void DemoGetPower(double base, int exponent);
void Foo(double a);
void SecondFoo(double& a);
void ThirdFoo(double* a);
void DoubleSorting(double* arr);
int* MakeRandomArray(int arraySize);
int* ReadArray(int count);
int CountPositiveValues(int* values, int count);
int GetIndexOfMax(double* array);