#include "ProductsList.h"
#include "Cart.h"

int main()
{
	int number = 5;
	Product* listProducts = new Product[number];

	listProducts[0] = Product("Rice", "White, 1 kg", 69);
	listProducts[1] = Product("Eggs", "C0, 10", 57);
	listProducts[2] = Product("Oranges", "Orange, 1 kg", 150);
	listProducts[3] = Product("Milk", "5%", 50);
	listProducts[4] = Product("Chicken", "white, 1 kg", 200);

	ProductsList list = ProductsList(listProducts, number, "necessary");
	Cart cart = Cart(listProducts, number, "necessary");
	cout << "Amount of money for necessary: " << cart.GetFullCost() << endl;

	delete[] listProducts;

	number = 3;
	listProducts = new Product[number];

	listProducts[0] = Product("Potatoes", "White, 1 kg", 30);
	listProducts[1] = Product("Apples", "Red, 1 kg", 180);
	listProducts[2] = Product("Kiwi", "Green, 1 kg", 300);

	cart = Cart(listProducts, number, "vegetables");
	cout << "Amount of money for vegetables: " << cart.GetFullCost() << endl;

	delete[] listProducts;
	system("pause");
	return 0;
}