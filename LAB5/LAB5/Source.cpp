#include "Header.h"

int main()
{
	int choice = 0;
	while (true)
	{
		system("cls");
		cout << "Choose a choice:\n";
		cout << "0) Exit\n";
		cout << "1) Inheritance\n";
		cout << "2) Refactoring with base class extraction\n";
		cout << "3) Polymorphism\n";
		choice = CheckInt();
		switch (choice)
		{
			case 0:
			{
				return 0;
			}
			case 1:
			{
				PersonNode pers = PersonNode("Wade", "Louise", "Smith");
				TeacherNode teacher = TeacherNode("Dave", "Rose", "Johnson", "PhD");
				StudentNode student = StudentNode("Ivan", "Jane", "Brown", "", 2005);
				cout << "\nPersonNode: \n";
				ShowName(&pers);
				cout << "\nTeacherNode: \n";
				ShowName(&teacher);
				cout << "\nStudentNode: \n";
				ShowName(&student);
				system("pause");
				break;
			}
			case 2:
			{
				User** users = new User * [4]
				{
						new User(100000, "john1995", "1995john"),
						new User(100001, "ilon_mask", "X æ A-12"),
						new User(100002, "megaphone", "password"),
						new User(100003, "yogurt", "ksTPQzSu"),
				};
				PaidUser** paidUsers = new PaidUser * [4]
				{
					new PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
						new PaidUser(200001, "system_exe", "UgfkDGmU"),
						new PaidUser(200002, "RazorQ", "TBgRnbCP"),
						new PaidUser(200003, "schdub", "CetyQVID"),
				};
				string login = "megaphone";
				string password = "password";
				for (int i = 0; i < 4; i++)
				{
					if (users[i]->Login(login, password))
					{
						cout << "Signed in as: " << users[i]->GetLogin() << endl;
					}
				}
				login = "system_exe";
				password = "UgfkDGmU";
				for (int i = 0; i < 4; i++)
				{
					if (paidUsers[i]->Login(login, password))
					{
						cout << "Signed in as: " << paidUsers[i]->GetLogin() << endl;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					delete users[i];
				}
				delete[] users;
				for (int i = 0; i < 4; i++)
				{
					delete paidUsers[i];
				}
				delete[] paidUsers;
				system("pause");
				break;
			}
			case 3:
			{
				const int productsCount = 4;
				Product products[productsCount];
				products[0] = Product("Chicken", 250, meat);
				products[1] = Product("Cheese", 55, milk_products);
				products[2] = Product("Apple", 300, fruit);
				products[3] = Product("Milk", 80, milk_products);

				PercentDiscount* percentDicsount = new PercentDiscount(50, milk_products);
				CertificateDiscount* certificate = new CertificateDiscount(500, fruit);

				DiscountBase* arrDiscounts[2];
				arrDiscounts[0] = percentDicsount;
				arrDiscounts[1] = certificate;

				ShowCheckWithDiscount(arrDiscounts[1], products, productsCount);
			}
			default:
			{
				cout << "Choose one of the proposed items!\n";
				system("pause");
				break;
			}
		}
	}
}