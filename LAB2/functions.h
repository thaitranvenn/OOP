#pragma once
#include "ContactNode.h"
#include "DisciplineNode.h"
#include "MovieNode.h"
#include "FlightNode.h"
#include "RectangleNode.h"
#include "SongNode.h"
#include "TimeNode.h"
#include "CircleNode.h"
#include "MovieNodeWithGenre.h"
#include "EnumsNode.h"

int CheckInt();
void Sort(double* values, int count);
void DemoSort();
void WrongPointers();
void DemoEnums();
Colours ReadColor();
int CountRed(Colours* colors, int count);
void WriteColor(Colours colors);
int* CountColors(Colours* colors, int count);