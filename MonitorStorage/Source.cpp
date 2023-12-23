#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;
const int N = 2;

struct Monitors
{
	int id = 0;
	string manufacturer;
	string model;
	string color;
	float price = 0;
	float size = 0;
	string resolution;
	bool tvTuner = false;
	string type;
	string status = "Selling";
};

void showMonitors(Monitors m[])
{
	cout << "Id" << ' '
		<< "Manufacturer" << ' '
		<< "Model" << ' '
		<< "Color" << ' '
		<< "Price" << ' '
		<< "Display" << ' '
		<< "Resolution" << ' '
		<< "TV Tuner" << ' '
		<< "Type" << ' '
		<< "Status" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << m[i].id << ' '
			<< m[i].manufacturer << ' '
			<< m[i].model << ' '
			<< m[i].color << ' '
			<< m[i].price << '$' << ' '
			<< m[i].size << "\"" << ' '
			<< m[i].resolution << ' ';
		if (m[i].tvTuner == true)
		{
			cout << "Yes" << ' ';
		}
		else
		{
			cout << "No" << ' ';
		}
		cout << m[i].type << ' '
			<< m[i].status << endl;
	}
}

void checkId(Monitors m[])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (m[i].id==m[j].id)
			{
				m[j].id = rand() % 100 + 1;
			}
		}
	}
}

void enterMonitor(Monitors m[])
{
	string temp, temp1 = "Yes";
	int res;
	for (int i = 0; i < N; i++)
	{
		m[i].id = rand() % 100 + 1;
		checkId(m);

		cout << endl << "Monitor's Manufacturer: ";
		getline(cin, m[i].manufacturer);
		cout << endl << "Monitor's Model: ";
		getline(cin, m[i].model);
		cout << endl << "Monitor's Color: ";
		getline(cin, m[i].color);
		cout << endl << "Monitor's Price: ";
		cin >> m[i].price;
		cout << endl << "Monitor's Display: ";
		cin >> m[i].size;
		cin.ignore(1000, '\n');
		cout << endl << "Monitor's Rezolution: ";
		getline(cin, m[i].resolution);
		cout << "Does it have a TV Tuner?: ";
		getline(cin, temp);
		cout << "What is it's type?(New, Second-hand): ";
		getline(cin, m[i].type);


		res = temp.compare(temp1);
		if (res == 0)
		{
			m[i].tvTuner = true;
		}
	}
}

void ShowBiggestMonitor(Monitors m[])
{
	int index = 0;
	float bigM = m[0].size;
	for (int i = 0; i <= N; i++)
	{
		if (m[i].size > bigM)
		{
			bigM = m[i].size;
			index = i;
		}
	}

	cout << "The biggest size monitor in store is: " << endl;

	cout << m[index].id << ' '
		<< m[index].manufacturer << ' '
		<< m[index].model << ' '
		<< m[index].price << '$' << ' '
		<< m[index].size << "\"" << endl;
}

void searchMonitor(Monitors m[])
{
	string temp;
	cout << "Enter the brand of the monitors you want to see: ";
	getline(cin, temp);

	cout << endl << "Id" << ' '
		<< "Manufacturer" << ' '
		<< "Model" << ' '
		<< "Color" << ' '
		<< "Price" << ' '
		<< "Display" << ' '
		<< "Resolution" << ' '
		<< "TV Tuner" << ' '
		<< "Type" << ' '
		<< "Status" << endl;

	for (int i = 0; i < N; i++)
	{
		if (temp == m[i].manufacturer)
		{
			cout << m[i].id << ' '
				<< m[i].manufacturer << ' '
				<< m[i].model << ' '
				<< m[i].color << ' '
				<< m[i].price << '$' << ' '
				<< m[i].size << "\"" << ' '
				<< m[i].resolution << ' ';
			if (m[i].tvTuner == true)
			{
				cout << "Yes" << ' ';
			}
			else
			{
				cout << "No" << ' ';
			}
			cout << m[i].type << ' '
				<< m[i].status << endl;
		}
	}
}


void showSearchMenu(Monitors m[])
{
	int choice;
	do
	{
		cout << "1. Monitor with biggest resolution" << endl;
		cout << "2. Show Monitors from a brand" << endl;
		cout << "0. Back to Main Menu" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		switch (choice)
		{
		case 1:
			ShowBiggestMonitor(m);
			break;
		case 2:
			searchMonitor(m);
			break;
		default:
			cout << "There is no option corresponding to your choice!" << endl;
			break;
		}


	} while (choice != 0);
}

void sortMonitorsByPrice(Monitors m[])
{
	Monitors temp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (m[j].price > m[j + 1].price)
			{
				temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;
			}
		}
	}
}

void saveMonitorsInFile(Monitors m[])
{
	fstream fs;
	fs.open("Monitors.txt", ios::app);
	if (fs.fail())
	{
		cout << "The file could not be opened" << endl;
		exit(1);
	}

	for (int i = 0; i < N; i++)
	{
		fs << m[i].id << ' '
			<< m[i].manufacturer << ' '
			<< m[i].model << ' '
			<< m[i].color << ' '
			<< m[i].price << '$' << ' '
			<< m[i].size << "\"" << ' '
			<< m[i].resolution << ' '
			<<m[i].type<<' '
			<< m[i].status<<'\n';
	}

	fs.close();
	cout << "Data succesfully saved in file!" << endl;
}

int checkFileElements()
{
	ifstream ifs;
	int count = 0;
	char next;
	ifs.open("Monitors.txt", ios::in);
	ifs.get(next);
	while (!ifs.eof())
	{
		if (next=='\n')
		{
			count++;
		}
		ifs.get(next);
	}
	ifs.close();
	return count;
	
}

void inportMonitorsFromFile(Monitors m[])
{
	ifstream ifs;
	int numberOfElements = checkFileElements();
	ifs.open("Monitors.txt", ios::in);
	if (ifs.fail())
	{
		cout << "The file could not be opened" << endl;
		exit(1);
	}

	for (int i = 0; i < N; i++)
	{
		ifs >> m[i].id >> m[i].manufacturer >> m[i].model >> m[i].color >> m[i].price >> m[i].size >> m[i].size >> m[i].resolution >> m[i].type >> m[i].status;
	}

	ifs.close();

}

void showMonitorsFromFile(Monitors m[])
{
	ifstream ifs;
	char next;
	ifs.open("Monitors.txt", ios::in);
	if (ifs.fail())
	{
		cout << "The file could not be opened" << endl;
		exit(1);
	}
	ifs.get(next);
	while (!ifs.eof())
	{
		cout << next;
		ifs.get(next);
	}
	ifs.close();
}


void showMainMenu(Monitors m[])
{
	int choice;
	do
	{
		cout << "1. Enter Monitor" << endl;
		cout << "2. Show Monitor" << endl;
		cout << "3. Search Monitor" << endl;
		cout << "4. Sort Monitors By Price" << endl;
		cout << "5. Save Monitors In File" << endl;
		cout << "6. Show Monitors From File" << endl;
		cout << "7. Inport Monitors From File" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choice:";
		cin >> choice;
		cin.ignore(1000, '\n');

		switch (choice)
		{
		case 1:
			enterMonitor(m);
			break;
		case 2:
			showMonitors(m);
			break;
		case 3:
			showSearchMenu(m);
			break;
		case 4:
			sortMonitorsByPrice(m);
			break;
		case 5:
			saveMonitorsInFile(m);
			break;
		case 6:
			showMonitorsFromFile(m);
			break;
		case 7:
			inportMonitorsFromFile(m);
			break;
		case 0:
			break;
		default:
			cout << "There is no option corresponding to your choice!" << endl;
			break;
		}

	} while (choice != 0);

	cout << "Have a nice day!" << endl;
}

int main()
{
	Monitors m[N];
	showMainMenu(m);
	return 0;
}
