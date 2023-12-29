#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;
const int N = 1;

struct Monitors
{
	int id = 0;
	string manufacturer;
	string model;
	string color;
	float price = 0;
	float size = 0;
	string resolution;
	string tvTuner;
	string type;
	string status = "Selling";
};

void showMonitorsByManufacturer(Monitors m[])
{
	Monitors temp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (m[j].manufacturer > m[j + 1].manufacturer)
			{
				temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;
			}
		}
	}

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
			<< m[i].resolution << ' '
			<<m[i].tvTuner<<' '
		<< m[i].type << ' '
			<< m[i].status << endl;
	}

}

void showMonitorsBySize(Monitors m[])
{
	Monitors tempArr[N];
	int count = 0;

	float val;

	cout << "Select the size you want to see: ";
	cin >> val;
	cin.ignore(1000, '\n');

	for (int i = 0; i < N; i++)
	{
		if (m[i].size==val)
		{
			tempArr[count] = m[i];
			count++;
		}
	}

	Monitors temp;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (tempArr[j].manufacturer > tempArr[j + 1].manufacturer)
			{
				temp = tempArr[j];
				tempArr[j] = tempArr[j + 1];
				tempArr[j + 1] = temp;
			}
		}
	}

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
			<< m[i].resolution << ' '
			<< m[i].tvTuner << ' '
			<< m[i].type << ' '
			<< m[i].status << endl;
	}

}

void showMonitors(Monitors m[])
{
	int choice;
	do
	{
		cout << "1. Show Monitors by manufacturer" << endl;
		cout << "2. Show Monitors by chosen size" << endl;
		cout << "0. Back" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		switch (choice)
		{
		case 1:
			showMonitorsByManufacturer(m);
			break;
		case 2:
			showMonitorsBySize(m);
			break;
		default:
			cout << "There is no option corresponding to your choice!" << endl;
			break;
		}
		

	} while (choice !=0);
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
		getline(cin, m[i].tvTuner);
		cout << "What is it's type?(New, Second-hand): ";
		getline(cin, m[i].type);


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
				<< m[i].resolution << ' '
				<< m[i].tvTuner << ' '
				<< m[i].type << ' '
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
		case 0:
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
		ifs.ignore(1000, '$');
		ifs.ignore(1000, '"');
		ifs >> m[i].id >> m[i].manufacturer >> m[i].model >> m[i].color >> m[i].price >> m[i].size >> m[i].size >> m[i].resolution >> m[i].type >> m[i].status;
		ifs.ignore(1000, '\n');
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

void editByMan(Monitors m[])
{
	string manTemp;
	string modelTemp;
	bool flag=false;
	int currentId;
	int choice;

	cout << "Enter the manudacturer and model of the monitor you want to edit" << endl;
	cout << "Manudacturer: "; getline(cin, manTemp);
	cout << endl << "Model: "; getline(cin, modelTemp);
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (manTemp==m[i].manufacturer&&modelTemp==m[i].model)
		{
			flag = true;
			currentId = i;
			break;
		}
	}

	if (flag)
	{
		do
		{
			cout << "What do you want to change?" << endl;
			cout << "1. Serial Number" << endl;
			cout << "2. Manufacturer" << endl;
			cout << "3. Model" << endl;
			cout << "4. Color" << endl;
			cout << "5. Price" << endl;
			cout << "6. Size" << endl;
			cout << "7. Resolution" << endl;
			cout << "8. TV Tunner" << endl;
			cout << "9. Type" << endl;
			cout << "10. Status" << endl;
			cout << "0. Back" << endl;
			cout << "Your choice: ";
			cin >> choice;
			cin.ignore(1000, '\n');

			switch (choice)
			{
			case 1:
				cout << endl << "New Serial Number: ";
				cin >> m[currentId].id;
				cin.ignore(1000, '\n');
				break;
			case 2:
				cout << endl << "New Manufacturer: ";
				getline(cin, m[currentId].manufacturer);
				break;
			case 3:
				cout << endl << "New Model: ";
				getline(cin, m[currentId].model);
				break;
			case 4:
				cout << endl << "New Color: ";
				getline(cin, m[currentId].color);
				break;
			case 5:
				cout << endl << "New Price: ";
				cin >> m[currentId].price;
				cin.ignore(1000, '\n');
				break;
			case 6:
				cout << endl << "New Size: ";
				cin >> m[currentId].size;
				cin.ignore(1000, '\n');
				break;
			case 7:
				cout << endl << "New Resolution: ";
				getline(cin, m[currentId].resolution);
				break;
			case 8:
				cout << endl << "New TV Tunner status: ";
				getline(cin, m[currentId].tvTuner);
				break;
			case 9:
				cout << endl << "New Type: ";
				getline(cin, m[currentId].type);
				break;
			case 10:
				cout << endl << "New Status: ";
				getline(cin, m[currentId].status);
				break;
			case 0:
				break;
			default:
				cout << "There is no option corresponding to your choice!" << endl;
				break;
			}


		} while (choice != 0);
	}
	else
	{
		cout << "There is not an item with these attributes in the list!" << endl;
	}
}

void editBySerialNumber(Monitors m[])
{
	int id;
	bool flag = false;
	int currentId;
	int choice;

	cout << "Enter the serial number of the monitor you want to edit" << endl;
	cin >> id;

	for (int i = 0; i < N; i++)
	{
		if (id==m[i].id)
		{
			flag = true;
			currentId = i;
			break;
		}
	}

	if (flag)
	{
		do
		{
			cout << "What do you want to change?" << endl;
			cout << "1. Serial Number" << endl;
			cout << "2. Manufacturer" << endl;
			cout << "3. Model" << endl;
			cout << "4. Color" << endl;
			cout << "5. Price" << endl;
			cout << "6. Size" << endl;
			cout << "7. Resolution" << endl;
			cout << "8. TV Tunner" << endl;
			cout << "9. Type" << endl;
			cout << "10. Status" << endl;
			cout << "0. Back" << endl;
			cout << "Your choice: ";
			cin >> choice;
			cin.ignore(1000, '\n');

			switch (choice)
			{
			case 1:
				cout << endl << "New Serial Number: ";
				cin >> m[currentId].id;
				cin.ignore(1000, '\n');
				break;
			case 2:
				cout << endl << "New Manufacturer: ";
				getline(cin, m[currentId].manufacturer);
				break;
			case 3:
				cout << endl << "New Model: ";
				getline(cin, m[currentId].model);
				break;
			case 4:
				cout << endl << "New Color: ";
				getline(cin, m[currentId].color);
				break;
			case 5:
				cout << endl << "New Price: ";
				cin >> m[currentId].price;
				cin.ignore(1000, '\n');
				break;
			case 6:
				cout << endl << "New Size: ";
				cin >> m[currentId].size;
				cin.ignore(1000, '\n');
				break;
			case 7:
				cout << endl << "New Resolution: ";
				getline(cin, m[currentId].resolution);
				break;
			case 8:
				cout << endl << "New TV Tunner status: ";
				getline(cin, m[currentId].tvTuner);
				break;
			case 9:
				cout << endl << "New Type: ";
				getline(cin, m[currentId].type);
				break;
			case 10:
				cout << endl << "New Status: ";
				getline(cin, m[currentId].status);
				break;
			case 0:
				break;
			default:
				cout << "There is no option corresponding to your choice!" << endl;
				break;
			}


		} while (choice != 0);
	}
	else
	{
		cout << "There is not an item with these attributes in the list!" << endl;
	}
}

void promotionalPrice(Monitors m[])
{
	int id;
	bool flag = false;
	int currentId;
	float discount;

	cout << "Enter the serial number of the desired monitor: ";
	cin >> id;
	cin.ignore(1000, '\n');
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (id==m[i].id)
		{
			currentId = i;
			flag = true;
			break;
		}
	}

	if (flag)
	{
		cout << "Enter the discount(%): ";
		cin >> discount;
		m[currentId].price = m[currentId].price - (m[currentId].price * (discount / 100));
		cout << "Price with discount: " << m[currentId].price << '$' << endl;
	}
	else
	{
		cout << "There is not an item with that serial number in the list!" << endl;
	}
}

void editEntry(Monitors m[])
{

	int choice;

	do
	{
		cout << "1. Edit By Manufacturer and Model" << endl;
		cout << "2. Edit By Serial Number" << endl;
		cout << "3. Set a promotional price" << endl;
		cout << "0. Back" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		switch (choice)
		{
		case 1:
			editByMan(m);
			break;
		case 2:
			editBySerialNumber(m);
			break;
		case 3:
			promotionalPrice(m);
			break;
		case 0:
			break;
		default:
			cout << "There is no option corresponding to your choice!" << endl;
			break;
		}

	} while (choice !=0);
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
		cout << "8. Edit Entries" << endl;
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
		case 8:
			editEntry(m);
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
