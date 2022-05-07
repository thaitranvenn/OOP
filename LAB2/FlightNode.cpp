#pragma once
#include <iostream>
#include "functions.h"
#include "FlightNode.h"

using namespace std;

void ShowFlightNode(FlightNode* temp)
{
    cout << "\nFlight: " << temp->DeparturePoint << " -- " << temp->DestinationPoint << endl;
};

void DemoFlight()
{
    FlightNode* temp = new FlightNode;
    temp->DeparturePoint = "Moscow";
    temp->DestinationPoint = "Tomsk";
    temp->time = 120;
    ShowFlightNode(temp);
    delete temp;
}

FlightNode* CinFlightNode()
{
    FlightNode* temp = new FlightNode;
    cout << "Enter the starting point: ";
    cin >> temp->DeparturePoint;
    cout << endl;
    cout << "Enter destination: ";
    cin >> temp->DestinationPoint;
    cout << endl;
    cout << "Enter time: ";
    temp->time = CheckInt();
    cout << endl;
    return temp;
};

void DemoFlightAdress()
{
    FlightNode temp;
    cout << "Temp address: " << &temp << "\n";
    temp.DeparturePoint = "Kazan";
    temp.DestinationPoint = "Saint_Petersburg";
    temp.time = 90;
    ShowFlightNode(&temp);
    FlightNode* NewTemp = &temp;
    cout << endl << endl << "NewTemp address: " << NewTemp << "\n";
    ShowFlightNode(NewTemp);
    cout << endl << endl;
    NewTemp->DeparturePoint = "Moscow";
    NewTemp->DestinationPoint = "Tomsk";
    NewTemp->time = 120;
    cout << endl;
    cout << "NewTemp address:" << NewTemp;
    ShowFlightNode(NewTemp);
    cout << "Temp: " << &temp << endl;
    ShowFlightNode(&temp);
};

void DemoDynamicFlight()
{
    FlightNode* Flight;
    Flight = CinFlightNode();
    cout << "\nNow in the flight:\n";
    ShowFlightNode(Flight);
    delete Flight;
};


void DemoDynamicFlights()
{
    int count;
    do
    {
        cout << "Enter the number of flights: ";
        count = CheckInt();
        cout << endl;
    } while (count <= 0);
    FlightNode** Flight = new FlightNode * [count];
    for (int i = 0; i < count; i++)
    {
        Flight[i] = CinFlightNode();
    }
    cout << endl;
    cout << "Now in the flight:\n";
    for (int i = 0; i < count; i++)
    {
        ShowFlightNode(Flight[i]);
    }
    cout << endl;
    FindShortestFlight(Flight, count);
    for (int i = 0; i < count; i++)
    {
        delete Flight[i];
    }
};


void FindShortestFlight(FlightNode** flights, int count)
{
    int min = flights[0]->time;
    for (int i = 0; i < count; i++)
    {
        if (flights[i]->time < min)
        {
            min = flights[i]->time;
        }
    }
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        if (flights[i]->time == min)
        {
            cout << "Shortest flight: ";
            ShowFlightNode(flights[i]);
            break;
        }
    }
    cout << endl;
};

FlightNode* MakeFlight(const char* DeparturePoint, const char* DestinationPoint, int time)
{
    FlightNode* temp = new FlightNode;
    temp->DeparturePoint = DeparturePoint;
    temp->DestinationPoint = DestinationPoint;
    temp->time = time;
    return temp;
};

FlightNode* CopyFlight(FlightNode* Flight)
{
    FlightNode* temp = new FlightNode;
    temp->DeparturePoint = Flight->DeparturePoint;
    temp->DestinationPoint = Flight->DestinationPoint;
    temp->time = Flight->time;
    return temp;
};