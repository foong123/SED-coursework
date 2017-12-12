#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "Vehicle_Class.h"
using namespace std;
void display();
int coupon();

void display()
{
	Vehicle arr_vehicle[100];
	Vehicle vehicle;
	Toyota toyota;
	Honda honda;
	Camry camry;
	Altis altis;
	Vios vios;
	Accord accord;
	Civic civic;
	City city;
	arr_vehicle[0] = vehicle;
	arr_vehicle[1] = toyota;
	arr_vehicle[2] = honda;
	arr_vehicle[3] = camry;
	arr_vehicle[4] = altis;
	arr_vehicle[5] = vios;
	arr_vehicle[6] = accord;
	arr_vehicle[7] = civic;
	arr_vehicle[8] = city;
	Vehicle* option;
	int i = 1;
	char a;
	while (i == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== MENU ==========\n" << "'1' - General Vehicles\n" << "'2' - Special Toyota Cars\n";
		cout << "'3' - Toyota Camry\n" << "'4' - Toyota Altis\n";
		cout << "'5' - Toyota Vios\n" << "'6' - Special Honda Cars\n";
		cout << "'7' - Honda Accors\n" << "'8' - Honda Civic\n";
		cout << "'9' - Honda City\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		if (a == '1')
		{
			option = &vehicle;
			option->menu();
			break;
		}
		if (a == '2')
		{
			option = &toyota;
			option->menu();
			break;
		}
		if (a == '3')
		{
			option = &camry;
			option->menu();
			break;
		}
		if (a == '4')
		{
			option = &altis;
			option->menu();
			break;
		}
		if (a == '5')
		{
			option = &vios;
			option->menu();
			break;
		}
		if (a == '6')
		{
			option = &honda;
			option->menu();
			break;
		}
		if (a == '7')
		{
			option = &accord;
			option->menu();
			break;
		}
		if (a == '8')
		{
			option = &civic;
			option->menu();
			break;
		}
		if (a == '9')
		{
			option = &city;
			option->menu();
			break;
		}
		if (a == 'q' || a == 'Q')
		{
			i = 2;
			cout << "\n\nProgram quitting...\n\n";
		}
		else
			cout << endl;
	}
}
int coupon()
{
	srand(time(0));
	int number;
	number = rand() % 10 + 1;
	int tries = 3;
	int guess;
	cout << "Coupon codes is valid between 1-10" << endl;
	do {
		cout << "You have " << tries << " tries remaining\n\n";
		cout << "Enter your coupon: " << endl;
		cin >> guess;
		tries--;
		if (tries <= 0)
		{
			break;
		}
		else if (guess > number)
		{
			cout << "Invalid Coupon...\n\n" << endl;
		}
	} while (guess != number);
	if (guess == number)
	{
		cout << "Congratulations you have enter the correct coupon!\n" << endl;
	}
	else
	{
		cout << "Sorry you have enter the wrong coupon\n\n";
		display();
		system("pause");
		exit(0);
	}
	tries = 0;
}

int main()
{
	string name;
	cout << "Enter name please\n>> ";
	getline(cin, name);
	cout << "\nHello Mr." << name << endl << endl;
	display();
	system("pause");
	return 0;
}