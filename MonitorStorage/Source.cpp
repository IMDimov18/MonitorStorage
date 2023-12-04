#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int N = 100;

struct Monitors
{
	int id;
		string manufacturer;
		string model;
		string color;
		float price;
		float size;
		string resolution;
		bool tvTuner=false;
		string type;
		string status = "Selling";
};

void showMonitors(Monitors m[],int n)
{
	cout << "Id" << setw(10)
		<< "Manufacturer" << setw(10)
		<< "Model" << setw(10)
		<< "Color" << setw(10)
		<< "Price" << setw(10)
		<< "Display" << setw(10)
		<< "Resolution" << setw(10)
		<< "TV Tuner" << setw(10)
		<< "Type" << setw(10)
		<< "Status" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << m[i].id << setw(20)
			<< m[i].manufacturer << setw(20)
			<< m[i].model << setw(20)
			<< m[i].color << setw(20)
			<< m[i].price << '$' << setw(20)
			<< m[i].size << "\"" << setw(20)
			<< m[i].resolution << setw(20);
		if (m[i].tvTuner == true)
		{
			cout << "Yes" << setw(20);
		}
		else
		{
			cout << "No" << setw(20);
		}
		cout << m[i].type << setw(20)
			<< m[i].status << endl;
	}
}

void enterMonitor(Monitors m[], int n)
{
	string temp,temp1="Yes";
	int res;
	for (int i = 1; i <= n; i++)
	{
		m[i].id = i;
		cout<<endl << "Monitor's Manufacturer: ";
		getline(cin, m[i].manufacturer);
		cout << endl << "Monitor's Model: ";
		getline(cin, m[i].model);
		cout << endl << "Monitor's Color: ";
		getline(cin, m[i].color);
		cout << endl << "Monitor's Price: ";
		cin >> m[i].price;
		cout << endl << "Monitor's Display: ";
		cin >> m[i].size;
		cout << endl << "Monitor's Rezolution: ";
		getline(cin, m[i].resolution);
		cout << "Does it have a TV Tuner?: ";
		getline(cin, temp);
		cout << "What is it's type?(New, Second-hand): ";
		getline(cin, m[i].type);


		res = temp.compare(temp1);
		if (res==0)
		{
			m[i].tvTuner = true;
		}
	}
}

void showMainMenu(Monitors m[])
{
	int choice;
	int n;
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
			cout << "How many monitors do you want to enter?: "; cin >> n;
			enterMonitor(m, n);
			break;
		case 2:
			showMonitors(m, n);
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
	Monitors m[N];
	showMainMenu(m);
	return 0;
}