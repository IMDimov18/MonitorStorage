#include <iostream>
#include <string>
using namespace std;
const int N = 5;

struct Monitors
{
	int id;
		string manufacturer;
		string model;
		string color;
		float price;
		float size;
		float rezolution;
		bool tvTuner;
		string type;
		string status;
};

void showMainMenu()
{
	int choice;

	do
	{
		cout << "1. Enter Monitor" << endl;
		cout << "2. Show Monitor" << endl;
		cout << "3. Search Monitor" << endl;
		cout << "4. Sort Monitors" << endl;
		cout << "5. Save Monitors" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			break;
		default:
			cout << "There is no option corresponding to your choice!" << endl;
			break;
		}

	} while (choice!=0);

	cout << "Have a nice day!" << endl;
}

int main()
{
	showMainMenu();
	return 0;
}