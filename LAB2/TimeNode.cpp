#pragma once
#include <iostream>
#include "TimeNode.h"
#include "functions.h"

using namespace std;

void ShowTimeNode(TimeNode* temp)
{
    cout << "\nTime: " << temp->hours << " hour " << temp->minutes << " minute " << temp->seconds << " second." << endl;
};

void DemoTime()
{
    TimeNode* temp = new TimeNode;
    temp->hours = 20;
    temp->minutes = 10;
    temp->seconds = 59;
    ShowTimeNode(temp);
    delete temp;
};

TimeNode* CinTimeNode()
{
    TimeNode* temp = new TimeNode;
    do
    {
        cout << "Enter hour: ";
        temp->hours = CheckInt();
    } while ((temp->hours > 23) || (temp->hours) < 0);
    do
    {
        cout << "Enter minute: ";
        temp->minutes = CheckInt();
    } while ((temp->minutes > 59) || (temp->minutes < 0));
    do
    {
        cout << "Enter second: ";
        temp->seconds = CheckInt();
    } while ((temp->seconds > 59) || (temp->seconds < 0));
    return temp;
}

void DemoTimeAdress()
{
    TimeNode temp;
    temp.hours = 23;
    temp.minutes = 12;
    temp.seconds = 43;
    cout << "\nTemp Address: " << &temp << endl;
    ShowTimeNode(&temp);
    TimeNode* NewTemp = new TimeNode;
    cout << "\nNewTemp address: " << NewTemp << endl;
    ShowTimeNode(NewTemp);
    NewTemp->hours = 22;
    NewTemp->minutes = 45;
    NewTemp->seconds = 12;
    cout << endl;
    ShowTimeNode(NewTemp);
};

TimeNode* MakeTime(int hours, int minutes, int seconds)
{
    TimeNode* temp = new TimeNode;
    temp->hours = hours;
    temp->minutes = minutes;
    temp->seconds = seconds;
    return temp;
};

TimeNode* CopyTime(TimeNode* time)
{
    TimeNode* temp = new TimeNode;
    temp->hours = time->hours;
    temp->minutes = time->minutes;
    temp->seconds = time->seconds;
    return temp;
};