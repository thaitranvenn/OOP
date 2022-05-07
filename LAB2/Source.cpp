#include <iostream>
#include "functions.h"
#include "ContactNode.h"
#include "DisciplineNode.h"
#include "MovieNode.h"
#include "FlightNode.h"
#include "RectangleNode.h"
#include "SongNode.h"
#include "TimeNode.h"
#include "CircleNode.h"
#include "EnumsNode.h"
#include "MovieNodeWithGenre.h"

using namespace std;

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============= MENU =============";
		cout << "\n\t0. EXIT";
		cout << "\n\t1. DemoSort";
		cout << "\n\t2. DEMO functions for structures";
		cout << "\n\t3. Enter the Rectangle";
		cout << "\n\t4. Enter the Flight";
		cout << "\n\t5. Enter the Movie";
		cout << "\n\t6. Enter the Time";
		cout << "\n\t7. NewAddress to function";
		cout << "\n\t8. WrongPointers";
		cout << "\n\t9. (2.2.5.1-2.2.5.2)";
		cout << "\n\t10.DemoReadAndWriteRectangles";
		cout << "\n\t11.Exchange";
		cout << "\n\t12.Maximum length of the rectangle";
		cout << "\n\t13.Maximum area of the rectangle";
		cout << "\n\t14.DemoDynamicFlight";
		cout << "\n\t15.DemoDynamicFlights and FindShortestFlight";
		cout << "\n\t16.Circle";
		cout << "\n\t17.Make and Copy 4x nodes";
		cout << "\n\t18.DemoEnums and WriteColor";
		cout << "\n\t19.ReadColor and WriteColor and CountRed and CountColors";
		cout << "\n\t20.DemoMovieWithGenre + MakeMovieWithGenre";
		cout << "\n\t21.DemoMovieWithGenreForCount + CountMoviesByGenre";
		cout << "\n\t22.FindBestGenreMovie";
		cout << "\n\n\t\t=============== END =============\n";
		int number = CheckInt();
		switch (number)
		{
		case 0:
		{
			cout << "Exitting program...\n";
			return 0;
		}
		case 1:
		{
			DemoSort();
			cout << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\nDemoRectangle:\n";
			DemoRectangle();
			cout << "\nDemoFlight:\n";
			DemoFlight();
			cout << "\nDemoMovie:\n";
			DemoMovie();
			cout << "\n\nDemoTime:\n";
			DemoTime();
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			int count;
			do
			{
				cout << "Enter the number of times: ";
				count = CheckInt();
				cout << endl;
			} while (count < 0);
			RectangleNode** Rectangle = new RectangleNode * [count];
			for (int i = 0; i < count; i++)
			{
				cout << "Enter rectangle " << i + 1 << "th :";
				Rectangle[i] = CinRectangleNode();
			}
			for (int i = 0; i < count; i++)
			{
				cout << "\nRectangle " << i + 1 << "th :";
				ShowRectangleNode(Rectangle[i]);
			}
			cout << endl;
			system("pause");
			break;
		}
		case 4:
		{
			int count;
			do
			{
				cout << "Enter the number of times: ";
				count = CheckInt();
				cout << endl;
			} while (count < 1);
			FlightNode** Flight = new FlightNode * [count];
			for (int i = 0; i < count; i++)
			{
				cout << "Enter flight " << i + 1 << ":\n";
				Flight[i] = CinFlightNode();
			}
			cout << endl << endl;
			for (int i = 0; i < count; i++)
			{
				cout << "Flight " << i + 1 << "th :\n";
				ShowFlightNode(Flight[i]);
			}
			system("pause");
			break;
		}
		case 5:
		{
			int count;
			do
			{
				cout << "Enter the number of times: ";
				count = CheckInt();
				cout << endl;
			} while (count < 0);
			MovieNode** Movie = new MovieNode * [count];
			for (int i = 0; i < count; i++)
			{
				cout << "Enter film " << i + 1 << "th :\n";
				Movie[i] = CinMovieNode();
			}
			cout << endl << endl;
			for (int i = 0; i < count; i++)
			{
				cout << "Film " << i + 1 << "th :\n";
				ShowMovieNode(Movie[i]);
			}
			system("pause");
			break;
		}
		case 6:
		{
			int count;
			do
			{
				cout << "Enter the number of times: ";
				count = CheckInt();
				cout << endl;
			} while (count < 0);
			TimeNode** Time = new TimeNode * [count];
			for (int i = 0; i < count; i++)
			{
				cout << "Enter time " << i + 1 << "th :\n";
				Time[i] = CinTimeNode();
			}
			cout << endl << endl;
			for (int i = 0; i < count; i++)
			{
				cout << "Time " << i + 1 << "th :\n";
				ShowTimeNode(Time[i]);
				cout << endl;
			}
			system("pause");
			break;
		}
		case 7:
		{
			cout << "\nRectangle";
			DemoRectangleAdress();
			cout << "\nFlight";
			DemoFlightAdress();
			cout << "\nMovie";
			DemoMovieAdress();
			cout << "\nTime";
			DemoTimeAdress();
			system("pause");
			break;
		}
		case 8:
		{
			WrongPointers();
			cout << "If the program started, then you did not remove /**/ in the function.\n";
			system("pause");
			break;
		}
		case 9:
		{
			RectangleNode rectangle;
			ReadRectangle(rectangle);
			WriteRectangle(rectangle);
			cout << endl;
			system("pause");
			break;
		}
		case 10:
		{
			DemoReadAndWriteRectangles();
			system("pause");
			break;
		}
		case 11:
		{
			RectangleNode rectangle1;
			RectangleNode rectangle2;
			ReadRectangle(rectangle1);
			ReadRectangle(rectangle2);
			cout << "\nInformation rectangles: ";
			cout << "\nRectangle1: ";
			WriteRectangle(rectangle1);
			cout << "\nRectangle2: ";
			WriteRectangle(rectangle2);

			cout << "\nAfter Exchange: ";
			Exchange(rectangle1, rectangle2);
			cout << "\nRectangle1: ";
			WriteRectangle(rectangle1);
			cout << "\nRectangle2: ";
			WriteRectangle(rectangle2);
			system("pause");
			break;
		}
		case 12:
		{
			int count;
			do
			{
				cout << "\nEnter the number of rectangle: ";
				count = CheckInt();
			} while (count <= 0);
			RectangleNode* Rectangle = new RectangleNode[count];
			for (int i = 0; i < count; i++)
			{
				cout << "\nRectangle " << i + 1 << endl;
				ReadRectangle(Rectangle[i]);
			}
			FindRectangle(Rectangle, count);
			delete[] Rectangle;
		}
		case 13:
		{
			int count;
			do
			{
				cout << "\nEnter the number of rectangle: ";
				count = CheckInt();
			} while (count <= 0);
			RectangleNode* Rectangle = new RectangleNode[count];
			for (int i = 0; i < count; i++)
			{
				cout << "Прямоугольник " << i + 1;
				cout << endl;
				ReadRectangle(Rectangle[i]);
			}
			FindMaxRectangle(Rectangle, count);
			system("pause");
			break;
		}
		case 14:
		{
			DemoDynamicFlight();
			system("pause");
			break;
		}
		case 15:
		{
			DemoDynamicFlights();
			system("pause");
			break;
		}
		case 16:
		{
			DemoCircle();
			system("pause");
			cout << "\n=======================\n";
			DemoCircleWithMakeAndCopy();
			system("pause");
			break;
		}
		case 17:
		{
			cout << "\nFlight: ";
			FlightNode* Flight = MakeFlight("Moscow", "Tokyo", 200);
			cout << endl;
			ShowFlightNode(Flight);

			cout << "\nFlightCopy: ";
			FlightNode* FlightCopy = CopyFlight(Flight);
			ShowFlightNode(FlightCopy);
			system("pause");

			MovieNode* Movie = MakeMovie("Tom and Jerry", 400, 1999, "Comedy", 9.0);
			cout << "\nMovie: ";
			ShowMovieNode(Movie);

			cout << "\nMovieCopy: ";
			MovieNode* MovieCopy = CopyMovie(Movie);
			ShowMovieNode(MovieCopy);
			system("pause");

			RectangleNode* Rectangle = MakeRectangle("Red", 20, 30);
			cout << "\nRectangle: ";
			ShowRectangleNode(Rectangle);

			cout << "\nRectangleCopy: ";
			RectangleNode* RectangleCopy = CopyRectangle(Rectangle);
			ShowRectangleNode(RectangleCopy);
			system("pause");

			TimeNode* Time = MakeTime(12, 23, 34);
			cout << "\nTime: ";
			ShowTimeNode(Time);

			cout << "\nTimeCopy: ";
			TimeNode* TimeCopy = CopyTime(Time);
			ShowTimeNode(TimeCopy);
			system("pause");
			break;
		}
		case 18:
		{
			DemoEnums();
			system("pause");
			break;
		}
		case 19:
		{
			int count = 0;
			do
			{
				cout << "\nEnter number of colors: ";
				count = CheckInt();
			} while (count <= 0);
			Colours* Colors = new Colours[count];
			for (int i = 0; i < count; i++)
			{
				Colors[i] = ReadColor();
			}
			cout << "\nInformation colors: ";
			for (int i = 0; i < count; i++)
			{
				WriteColor(Colors[i]);
			}
			cout << "\n\nNumber of Red Color: " << CountRed(Colors, count);
			int* CountColor = CountColors(Colors, count);
			for (int i = 0; i < Red + 1; i++)
			{
				switch (i)
				{
				case Red:
				{
					cout << "\nRed: " << CountColor[i];
					break;
				}
				case Orange:
				{
					cout << "\nOrange: " << CountColor[i];
					break;						}
				case Yellow:
				{
					cout << "\nYellow: " << CountColor[i];
					break;
				}
				case Blue:
				{
					cout << "\nBlue: " << CountColor[i];
					break;
				}
				case Pink:
				{
					cout << "\nPink: " << CountColor[i];
					break;
				}
				case Purple:
				{
					cout << "\nPurple: " << CountColor[i];
					break;
				}
				case Green:
				{
					cout << "\nGreen: " << CountColor[i];
					break;
				}
				}
			}
			delete[] CountColor;
			system("pause");
			break;
		}
		case 20:
		{
			DemoMovieWithGenre();
			system("pause");
			break;
		}
		case 21:
		{
			DemoMovieWithGenreForCount();
			system("pause");
			break;
		}
		case 22:
		{
			int count = 0;
			do
			{
				cout << "\nEnter the number of numbers: ";
				count = CheckInt();
			} while (count <= 0);
			MovieNodeWithGenre** Movie = new MovieNodeWithGenre * [count];
			for (int i = 0; i < count; i++)
			{
				Movie[i] = CinMovieNodeWithGenrePointer();
			}
			cout << "\n0 - Comedy; 1 - Drama; 2 - Thriller; 3 - Action; 4 - Horrors; 5 - Crimainal";

			int number = 0;
			do
			{
				cout << "\nEnter the number of genre looking for: ";
				number = CheckInt();
			} while ((number < 0) || (number > 5));
			cout << "\nHighest rated movie in selected genre: \n";
			MovieNodeWithGenre* temp;
			switch (number)
			{
			case Comedy:
			{
				temp = FindBestGenreMovie(Movie, count, Comedy);
				if (temp->rating != -1)
				{
					ShowMovieNodeWithGenre(temp);
				}
				else
				{
					cout << "\nNot in the movie list!";
				}
				break;
			}
			case Drama:
			{
				temp = FindBestGenreMovie(Movie, count, Drama);
				if (temp->rating != -1)
				{
					ShowMovieNodeWithGenre(temp);
				}
				else
				{
					cout << "\nNot in the movie list!";
				}
				break;
			}
			case Thriller:
			{
				temp = FindBestGenreMovie(Movie, count, Thriller);
				if (temp->rating != -1)
				{
					ShowMovieNodeWithGenre(temp);
				}
				else
				{
					cout << "\nNot in the movie list!";
				}
				break;
			}
			case Action:
			{
				temp = FindBestGenreMovie(Movie, count, Action);
				if (temp->rating != -1)
				{
					ShowMovieNodeWithGenre(temp);
				}
				else
				{
					cout << "\nNot in the movie list!";
				}
				break;
			}
			case Horrors:
			{
				temp = FindBestGenreMovie(Movie, count, Horrors);
				if (temp->rating != -1)
				{
					ShowMovieNodeWithGenre(temp);
				}
				else
				{
					cout << "\nNot in the movie list!";
				}
				break;
			}
			case Criminal:
			{
				temp = FindBestGenreMovie(Movie, count, Criminal);
				if (temp->rating != -1)
				{
					ShowMovieNodeWithGenre(temp);
				}
				else
				{
					cout << "\nNot in the movie list!";
				}
				break;
			}
			}
			system("pause");
			break;
		}
		default:
		{
			cout << "Please enter correct!\n";
			system("pause");
			break;
		}
		}

	}
}