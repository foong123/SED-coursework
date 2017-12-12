#pragma once
#ifndef Vehicle_Class_Header
#define Vehicle_Class_Header
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void display();
int coupon();

class Vehicle
{
public:
	string model, color;
	Vehicle();
	Vehicle(string, string, float);
	float getPrice();
	void setPrice(float);
	void own();
	void loan();
	virtual void menu();
	void chosen();
private:
protected:
	float price;
};

Vehicle::Vehicle(string m, string c, float p)
{
	model = m;
	color = c;
	setPrice(p);
	cout << "Model:" << model << endl;
	cout << "Color:" << color << endl;
	cout << "Price:" << getPrice() << endl;
}
Vehicle::Vehicle()
{
	model = "Default Model";
	color = "Silver";
	price = 0;
}

float Vehicle::getPrice()
{
	return price;
}

void Vehicle::setPrice(float p)
{
	price = p;
}

void Vehicle::own()
{
	cout << "Congratulation! You have own a " << model << endl;
	cout << "The color of your car is " << color << endl;
}

void Vehicle::loan()
{
	char choice;
	cout << "DO you want to borrow loan? (enter 'Y' for Yes, 'N' for No)\n";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		int year, month = 12, loan;
		float rate = 2.5;
		float total_interest, monthly_interest, monthly_installment;
		cout << "Enter number of years to borrow:";
		cin >> year;
		cout << "Enter number of cash need to loan:";
		cin >> loan;
		total_interest = (rate / 100) * (float)loan * (float)year;
		monthly_interest = total_interest / (month * year);
		monthly_installment = ((float)loan + total_interest) / (month * year);
		cout << "The total price need to pay is " << price - loan << endl;
		cout << "The monthly installment is " << setprecision(2) << fixed << monthly_installment << endl;
	}
	else if (choice == 'N' || choice == 'n')
	{
		cout << "WOW! You are very rich" << endl;
		cout << "The total price is:" << price << endl;
	}
	else
	{
		loan();
	}
}

void Vehicle::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== General Vehicle ==========\n";
		cout << "1. ";
		Vehicle V1 = Vehicle("Proton Saga", "Silver", 50000);
		cout << "\n2. ";
		Vehicle V2 = Vehicle("Perodua Myvi", "Red", 53000);
		cout << "\n3.";
		Vehicle V3 = Vehicle("Proton Wira", "Silver", 45000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		if (a == '1')
		{
			V1.chosen();
			V1.loan();
			V1.own();
			break;
		}
		if (a == '2')
		{
			V2.chosen();
			V2.loan();
			V2.own();
			break;
		}
		if (a == '3')
		{
			V3.chosen();
			V3.loan();
			V3.own();
			break;
		}
		if (a == 'b' || a == 'B')
		{
			display();
			break;
		}
		if (a == 'q' || a == 'Q')
		{
			q = 2;
			cout << "\n\nProgram quitting...\n\n";
		}
		else
			cout << endl;
	}
}

void Vehicle::chosen()
{
	cout << "The car model you have chosen is " << model << endl;
	cout << "The color is " << color << endl;
}

//
class Toyota : public Vehicle
{
public:
	Toyota() = default;
	Toyota(string model, string color, float price);
	void own();
	void menu() override;
	void discount();
};

void Toyota::own()
{
	cout << "Congratulation! You have own a " << model << endl;
	cout << "The color of your car is " << color << endl;
}

Toyota::Toyota(string model, string color, float price) :Vehicle(model, color, price)
{
}

void Toyota::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Special Toyota Cars ==========\n";
		cout << "1. ";
		Toyota T1 = Toyota("Toyota Estima", "Silver", 150000);
		cout << "\n2. ";
		Toyota T2 = Toyota("Toyota Vellfire", "Black", 160000);
		cout << "\n3.";
		Toyota T3 = Toyota("Limited Edition AE 86", "Black and White", 200000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				T1.chosen();
				T1.discount();
				break;
			}
			if (a == '2')
			{
				T2.chosen();
				T2.discount();
				break;
			}
			if (a == '3')
			{
				T3.chosen();
				T3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
			{
				menu();
			}
		}break;
	}
}
void Toyota::discount()
{
	char choice;
	double disc = 0.95;
	cout << "Do you have a coupon? (enter 'Y' for Yes, 'N' for No)\n";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		coupon();
		cout << "You will get a 5% discount\n";
		price = disc * getPrice();
		cout << "The new price of " << model << " is: " << price << endl;
		loan();
		own();
	}
	else if (choice == 'N' || choice == 'n')
	{
		cout << "No worries we still give u the discount of 5%\n";
		price = disc * getPrice();
		cout << "The new price of " << model << " is: " << price << endl;
		loan();
		own();
	}
	else
	{
		discount();
	}
}
//
class Camry : public Toyota
{
public:
	Camry() = default;
	Camry(string model, string color, float price);
	void own();
	void menu() override;
};

void Camry::own()
{
	cout << "Congratulation! " << model << " " << color << " is yours" << endl;
}

Camry::Camry(string model, string color, float price) :Toyota(model, color, price)
{
}

void Camry::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Toyota Camry ==========\n";
		cout << "1. ";
		Camry C1 = Camry("Camry Hybrid", "Silver", 150000);
		cout << "\n2. ";
		Camry C2 = Camry("Camry 2.5L", "Black", 130000);
		cout << "\n3.";
		Camry C3 = Camry("Camry Type R", "Red and White", 200000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				C1.chosen();
				C1.discount();
				break;
			}
			if (a == '2')
			{
				C2.chosen();
				C2.discount();
				break;
			}
			if (a == '3')
			{
				C3.chosen();
				C3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;
	}
}

//
class Altis : public Toyota
{
public:
	Altis() = default;
	Altis(string model, string color, float price);
	void own();
	void menu() override;
};

void Altis::own()
{
	cout << "Congratulation! You have own a " << model << " with a color of " << color << endl;
}

Altis::Altis(string model, string color, float price) :Toyota(model, color, price)
{
}

void Altis::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Toyota Altis ==========\n";
		cout << "1. ";
		Altis A1 = Altis("Altis 2.0L", "Pearl White", 120000);
		cout << "\n2. ";
		Altis A2 = Altis("Altis 2.0L", "Black", 110000);
		cout << "\n3.";
		Altis A3 = Altis("Altis Type R", "Blue and Yellow", 150000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				A1.chosen();
				A1.discount();
				break;
			}
			if (a == '2')
			{
				A2.chosen();
				A2.discount();
				break;
			}
			if (a == '3')
			{
				A3.chosen();
				A3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				A3.chosen();
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;
	}
}
//
class Vios : public Toyota
{
public:
	Vios() = default;
	Vios(string model, string color, float price);
	void own();
	void menu() override;
};

void Vios::own()
{
	cout << "Congratulation! You have own a " << model << endl;
	cout << "The color of your car is " << color << endl;
}

Vios::Vios(string model, string color, float price) :Toyota(model, color, price)
{
}

void Vios::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Toyota Vios ==========\n";
		cout << "1. ";
		Vios v1 = Vios("Vios 1.5L", "Silver", 65000);
		cout << "\n2. ";
		Vios v2 = Vios("Vios 1.5J", "Gold", 50000);
		cout << "\n3.";
		Vios v3 = Vios("Vios Type R", "Black and White", 200000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				v1.chosen();
				v1.discount();
				break;
			}
			if (a == '2')
			{
				v2.chosen();
				v2.discount();
				break;
			}
			if (a == '3')
			{
				v3.chosen();
				v3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;
	}
}

// Honda
class Honda : public Vehicle
{
public:
	Honda() = default;
	Honda(string model, string color, float price);
	void own();
	void menu() override;
	void discount();
};

void Honda::own()
{
	cout << "Congratulation! You have own a " << model << endl;
	cout << "The color of your car is " << color << endl;
}

Honda::Honda(string model, string color, float price) :Vehicle(model, color, price)
{
}

void Honda::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Special Honda cars ==========\n";
		cout << "1. ";
		Honda H1 = Honda("Honda CRV", "Silver", 80000);
		cout << "\n2. ";
		Honda H2 = Honda("Honda Jazz", "Black", 70000);
		cout << "\n3.";
		Honda H3 = Honda("Honda BRV", "Silver", 90000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				H1.chosen();
				H1.discount();
				break;
			}
			if (a == '2')
			{
				H2.chosen();
				H2.discount();
				break;
			}
			if (a == '3')
			{
				H3.chosen();
				H3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;
	}
}

void Honda::discount()
{
	char choice;
	double disc = 0.90;
	cout << "Do you have a coupon? (enter 'Y' for Yes, 'N' for No)\n";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		coupon();
		cout << "You will get a 10% discount and a goodie bag\n" << endl;
		cout << "The goodie bag contains shopping voucher worth RM200\n" << endl;
		price = disc * getPrice();
		cout << "The new price of " << model << " is: " << price << endl;
		loan();
		own();
	}
	else if (choice == 'N' || choice == 'n')
	{
		cout << "Feels Bad Man\n";
		loan();
		own();
	}
	else
	{
		discount();
	}
}
//
class Accord : public Honda
{
public:
	Accord() = default;
	Accord(string model, string color, float price);
	void own();
	void menu() override;
};

void Accord::own()
{
	cout << "Thank you for choosing Honda " << model << endl;
	cout << "We hope that you will enjoy our custom " << color << "paint" << endl;
}

Accord::Accord(string model, string color, float price) :Honda(model, color, price)
{
}

void Accord::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Honda Accord ==========\n";
		cout << "1. ";
		Accord a1 = Accord("Accord Hybrid", "Silver", 180000);
		cout << "\n2. ";
		Accord a2 = Accord("Accord 2.0L", "Black", 130000);
		cout << "\n3.";
		Accord a3 = Accord("Accord Type R", "Yellow and White", 200000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		while (true)
		{
			if (a == '1')
			{
				a1.chosen();
				a1.discount();
				break;
			}
			if (a == '2')
			{
				a2.chosen();
				a2.discount();
				break;
			}
			if (a == '3')
			{
				a3.chosen();
				a3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;
	}
}
//
class Civic : public Honda
{
public:
	Civic() = default;
	Civic(string model, string color, float price);
	void own();
	void menu() override;
};

void Civic::own()
{
	cout << "Good choice in choosing " << model << " instead of Toyota brand" << endl;
}

Civic::Civic(string model, string color, float price) :Honda(model, color, price)
{
}

void Civic::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Honda Civic ==========\n";
		cout << "1. ";
		Civic c1 = Civic("Civic Hybrid", "Silver", 130000);
		cout << "\n2. ";
		Civic c2 = Civic("Civic 2.0L", "Silver", 110000);
		cout << "\n3.";
		Civic c3 = Civic("Civic Type R", "Red", 150000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				c1.chosen();
				c1.discount();
				break;
			}
			if (a == '2')
			{
				c2.chosen();
				c2.discount();
				break;
			}
			if (a == '3')
			{
				c3.chosen();
				c3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;;
	}
}
//
class City : public Honda
{
public:
	City() = default;
	City(string model, string color, float price);
	void own();
	void menu() override;
};

void City::own()
{
	cout << "Your model is  " << model << endl;
	cout << "The color of your car is " << color << endl;
}
City::City(string model, string color, float price) :Honda(model, color, price)
{
}

void City::menu()
{
	int q;
	char a;
	q = 1;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Honda City ==========\n";
		cout << "1. ";
		City cty1 = City("City 1.6L", "Silver", 67000);
		cout << "\n2. ";
		City cty2 = City("City full specs", "Silver", 75000);
		cout << "\n3.";
		City cty3 = City("City Type R", "Black and Yellow", 80000);
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		while (true)
		{
			if (a == '1')
			{
				cty1.chosen();
				cty1.discount();
				break;
			}
			if (a == '2')
			{
				cty2.chosen();
				cty2.discount();
				break;
			}
			if (a == '3')
			{
				cty3.chosen();
				cty3.discount();
				break;
			}
			if (a == 'b' || a == 'B')
			{
				display();
				break;
			}
			if (a == 'q' || a == 'Q')
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
			}
			else
				menu();
		}break;
	}
}
#endif // !Vehicle_Class_H