/*	This is a long header file and it contains lots of function. So the main idea of this commenting is for	
	the user to understand how this header files works. The idea is very simple once the user understand
	the function in base class and second level derived, then the rest of the derived class will be the same. */
#pragma once
#ifndef Vehicle_Class_Header
#define Vehicle_Class_Header
#include <iostream>
#include <string>
#include <iomanip>
#define Month 12							// define month as 12 
#define Rate 2.5							// define interest rate as 2.5
using namespace std;
void display();								// This is needed. It will be explained further below
int coupon();								// This is needed because some of the functions need to call it.

class Vehicle								// Base class
{
public:
	string model, color;					// Initializing model and color as string.
	Vehicle();								// Default constructor
	Vehicle(string, string, float);			// Creating a constructor
	float getPrice();						// Getter function for price
	void setPrice(float);					// Setter function for price
	void chosen();							// function for chosen choice of the menu
	void own();								// function for owning the vehicle
	void loan();							// function for borrowing loan
	virtual void menu();					// virtual function for menu of each class (differ than the display function)
private:
protected:
	float price;							// hide the price 
};

Vehicle::Vehicle()										// Default constructor
{
	model = "Default Model";
	color = "Silver";
	price = 0;
}

Vehicle::Vehicle(string m, string c, float p)			//overloading constructor function
{
	model = m;
	color = c;
	setPrice(p);
	cout << "Model:" << model << endl;
	cout << "Color:" << color << endl;
	cout << "Price:" << getPrice() << endl;
}

float Vehicle::getPrice()								// getter function for price
{
	return price;
}

void Vehicle::setPrice(float p)							// setter function for price
{
	price = p;
}

void Vehicle::chosen()									// chosen function
{
	cout << "The car model you have chosen is " << model << endl;
	cout << "The color is " << color << endl;
}

void Vehicle::own()										// own function
{
	cout << "Congratulation! You have own a " << model << endl;
	cout << "The color of your car is " << color << endl;
}

void Vehicle::loan()								// loan function
{
	char choice;
	cout << "DO you want to borrow loan? (enter 'Y' for Yes, 'N' for No)\n";	// asking user to borrow loan or not	
	cin >> choice;									// This is to read the first character of a and ignore the rest
	cin.ignore(256, '\n');							// Ignore the rest of the character
	if (choice == 'Y' || choice == 'y')
	{
		int year,loan;						// Initialize year and loan
		float total_interest, monthly_interest, monthly_installment;		// Initialize variables
		cout << "Enter number of years to borrow:";							// Prompt user to enter year
		cin >> year;									
		cout << "Enter number of cash need to loan:";						// Prompt user to enter amount of cash to loan
		cin >> loan;
		total_interest = (Rate / 100) * (float)loan * (float)year;			// calculation of total interest
		monthly_installment = ((float)loan + total_interest) / (Month * year);		// calculate monthly installment
		cout << "The total price need to pay is " << price - loan << endl;		// final payment after borrowing loan
		cout << "The monthly installment is " << setprecision(2) << fixed << monthly_installment << endl;
		// shows the monthly installment with 2 decimal places with setprecision and fixed. 
	}
	else if (choice == 'N' || choice == 'n')			
	{
		cout << "WOW! You are very rich" << endl;					// Telling the user rich $$$
		cout << "The total price is:" << price << endl;				// Display original price of vehicle
	}
	else
	{
		loan();					//If user enter random characters, it will shows loan function 
	}
}

void Vehicle::menu()				// creating the menu of a specific class. In this case it will be base class menu
{
	int q = 1;						// Initialize and declare q = 1 for the looping
	char a;
	while (q == 1)					// Display menu of vehicle
	{
		cout << "Please select one: \n\n";
		cout << "========== General Vehicle ==========\n";
		cout << "1. ";
		Vehicle V1 = Vehicle("Proton Saga", "Silver", 50000);		// Creating object for the vehicle class 
		cout << "\n2. ";
		Vehicle V2 = Vehicle("Perodua Myvi", "Red", 53000);			// Creating object for the vehicle class 
		cout << "\n3.";
		Vehicle V3 = Vehicle("Proton Wira", "Silver", 45000);		// Creating object for the vehicle class 
		cout << "'b' - Return to Menu\n";							
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;						// This is to read the first character of a and ignore the rest
		cin.ignore(256, '\n');			// Ignore the rest of the character
		if (a == '1')					// Evaluating from the first character of a
		{
			V1.chosen();				// call the function of chosen
			V1.loan();					// call the function of loan once chosen function is executed
			V1.own();					// call the function of own once loan function is executed
			break;						// break from the while loop once it is finish executing all function
		}
		else if (a == '2')				// similar explanation with a == '1'
		{
			V2.chosen();				
			V2.loan();
			V2.own();
			break;
		}
		else if (a == '3')				// similar explanation with a == '1'
		{
			V3.chosen();			
			V3.loan();
			V3.own();
			break;
		}
		else if (a == 'b' || a == 'B')	// if the user input 'b' or 'B' it returns to the main menu
		{
			display();					// returns to display function
			break;
		}
		else if (a == 'q' || a == 'Q')	// To end the program 
		{
			q = 2;
			cout << "\n\nProgram quitting...\n\n";
		}
		else
			cout << endl;			//If user enter random characters,it will shows menu function 
	}
}

// Second level of derived class
// Toyota is the second level of derived class

class Toyota : public Vehicle			//Toyota class inherit from vehicle class
{
public:
	Toyota() = default;					// setting the default constructor
	Toyota(string model, string color, float price);			// Toyota constructor
	void menu() override;				// override menu function
	void discount();			// discount function only available in Toyota and its derived class but not Vehicle class
};

Toyota::Toyota(string model, string color, float price):Vehicle(model, color, price)	// inherits constructor function from vehicle class
{
	// empty
}

/*	In this Toyota menu function, I won't be explaining it in detailed as it has some similarities with vehicle menu function.
	However, I will explain some functions thats differ from the vehicle menu function.*/

void Toyota::menu()
{
	int q;
	char a;
	while (q == 1)
	{
		cout << "Please select one: \n\n";
		cout << "========== Special Toyota Cars ==========\n";
		cout << "1. ";
		Toyota T1 = Toyota("Toyota Estima", "Silver", 150000);		// Creating object for the Toyota class 
		cout << "\n2. ";
		Toyota T2 = Toyota("Toyota Vellfire", "Black", 160000);		// Creating object for the Toyota class 
		cout << "\n3.";
		Toyota T3 = Toyota("Limited Edition AE 86", "Black and White", 200000);		// Creating object for the Toyota class 
		cout << "'b' - Return to Menu\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');
		switch (a)					// Evaluating from the first character of a
		{
		case '1':
			{
				T1.chosen();		// call the function of chosen
				T1.discount();		// It can be seen that the loan and own function is missing. I will explain it in the discount function 
			}break;
		case '2':
			{
				T2.chosen();		// similar explanation for case '1'
				T2.discount();
			}break;
		case '3':
			{
				T3.chosen();		// similar explanation for case '1'
				T3.discount();
			}break;
		case 'b': case 'B':
			{
				display();			// returns to main menu (display function)
			}break;
		case 'q': case 'Q':			// quit the program
			{
				q = 2;				
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();		//If user enter random characters apart from the switch case it will shows menu function 
		}break;
	}
}
void Toyota::discount()		// Disount function
{
	char choice;				// initialize choice
	double disc = 0.95;			// initialize and declare discount
	cout << "Do you have a coupon? (enter 'Y' for Yes, 'N' for No)\n";  // asking user do they have coupon or not
	cin >> choice;
	cin.ignore(256, '\n');
	if (choice == 'Y' || choice == 'y')		// if have
	{
		coupon();			// call this function in cpp file and execute it
		cout << "You will get a 5% discount\n";			
		/*	this will only happens if the user successfully guess/enter the correct coupon. Here comes the 
			question on what happen if the user failed to guess the coupon?
			If we have a look at the coupon function in cpp file, once the user fails to guess
			the correct coupon the program will exit from this coupon function and leaves this line and 
			proceed into a new main menu. The vehicle selected by the user will be deleted and the user have to 
			select the vehicle once again	*/

		price = disc * getPrice();	// calculate the new price
		cout << "The new price of " << model << " is: " << price << endl;
		loan();				// run this once the new price is calculated
		own();				// run this once loan is executed
	}
	else if (choice == 'N' || choice == 'n')	// if dont have :(
	{
		cout << "No worries we still give u the discount of 5%\n";		// discount will be still be given if dont have coupon (YEAH!)
		price = disc * getPrice();			// calculate the new price
		cout << "The new price of " << model << " is: " << price << endl;
		loan();		// run this once the new price is calculated
		own();		// run this once loan is executed
	}
	else
	{
		discount();		//If user enter random characters, it will shows discount function 
	}
}

/* This will be the 3rd level of derived class. In the coursework, it says it needs 2 second level derived
	class. However, remember the comments I stated earlier at the top of the header. I will explain one side of the 
	class and the rest will the same. So I will continue with the explanation of this 3rd level derived class
	before I partially explain the second part of the second level derived class. Camry, Altis and Vios is the 
	3rd level of derived class. */

// 3rd level class: Camry class derived from Toyota
class Camry : public Toyota						//Camry class inherit from Toyota class and as well as vehicle class
{
public:
	Camry() = default;				// setting the default constructor
	Camry(string model, string color, float price);		// Camry constructor
	void menu() override;			// override menu function from the vehicle class
};

Camry::Camry(string model, string color, float price) :Toyota(model, color, price)		// inherits constructor function from vehicle class
{
	//empty
}

/*	In this Camry menu function, I won't be explaining it as it has the same function and body of the 
	Toyota menu function. Please see Toyota menu function commenting. Thank You.*/

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
		switch (a)
		{
		case '1':
			{
				C1.chosen();
				C1.discount();
			}break;
		case '2':
			{
				C2.chosen();
				C2.discount();
			}break;
		case '3':
			{
				C3.chosen();
				C3.discount();
			}break;
		case 'b': case 'B':
			{
				display();
			}break;
		case 'q': case 'Q':
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();
		}break;
	}
}

// 3rd level class: Altis class derived from Toyota
// Please see Camry class and Toyota menu function commenting. Thank You.
class Altis : public Toyota
{
public:
	Altis() = default;
	Altis(string model, string color, float price);
	void menu() override;
};

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
		switch (a)
		{
		case '1':
			{
				A1.chosen();
				A1.discount();
			}break;
		case '2':
			{
				A2.chosen();
				A2.discount();
			}break;
		case '3':
			{
				A3.chosen();
				A3.discount();
			}break;
		case 'b': case 'B':
			{
				display();
			}break;
		case 'q': case'Q':
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();
		}break;
	}
}

// 3rd level class: Vios class derived from Toyota
// Please see Camry class and Toyota menu function commenting. Thank You.
class Vios : public Toyota
{
public:
	Vios() = default;
	Vios(string model, string color, float price);
	void menu() override;
};

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
		switch (a)
		{
		case '1':
			{
				v1.chosen();
				v1.discount();
			}break;
		case '2':
			{
				v2.chosen();
				v2.discount();
			}break;
		case '3':
			{
				v3.chosen();
				v3.discount();
			}break;
		case 'b': case'B':
			{
				display();
			}break;
		case 'q': case'Q':
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();
		}break;
	}
}

/*	This is the second part of the second level derived class. Honda will be the second level
	derived class from the vehicle class. Once again the commenting of Honda and its 3rd level
	derived class will not be much emphasis as it is the same as the Toyota class.*/

// Honda class
class Honda : public Vehicle		//Honda class inherit from vehicle class
{
public:
	Honda() = default;			// setting the default constructor
	Honda(string model, string color, float price);		 // Honda Constructor
	void menu() override;		//overrride menu function
	void discount();	// discount function only available in Honda and its derived class
};

Honda::Honda(string model, string color, float price) :Vehicle(model, color, price) // inherits constructor function from vehicle class
{
	// empty
}

// Similar commenting with Toyota menu. Please see Toyota menu function commenting
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
		switch (a)
		{
		case '1':
			{
				H1.chosen();
				H1.discount();
			}break;
		case '2':
			{
				H2.chosen();
				H2.discount();
			}break;
		case '3':
			{
				H3.chosen();
				H3.discount();
			}break;
		case 'b': case 'B':
			{
				display();
			}break;
		case 'q':case 'Q':
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();
		}break;
	}
}

/*	The discount function here is similar to the Toyota. However there is a small twist in this discount 
	function in Honda.*/
void Honda::discount()
{
	char choice;
	double disc = 0.90;			// The discount in Toyota is lesser than Honda
	cout << "Do you have a coupon? (enter 'Y' for Yes, 'N' for No)\n";
	cin >> choice;
	cin.ignore(256, '\n');
	if (choice == 'Y' || choice == 'y')
	{
		coupon();
		cout << "You will get a 10% discount and a goodie bag\n" << endl;			// a free goodie bag :) 
		cout << "The goodie bag contains shopping voucher worth RM200\n" << endl;		// more gifts !
		price = disc * getPrice();		// Calculate the new price using Honda Discount
		cout << "The new price of " << model << " is: " << price << endl;
		loan();		// run this once the new price is calculated	
		own();		// run this once loan is executed
	}
	else if (choice == 'N' || choice == 'n')
	{
		cout << "Feels Bad Man\n";		// no discount nor goodie bags if do not have coupon :(
		loan();		// run this after 'feels bad man'
		own();		// run this once loan is executed
	}
	else
	{
		discount();
	}
}

// 3rd level class: Accord class derived from Honda
class Accord : public Honda		//Accord class inherit from Honda class and as well as vehicle class
{
public:
	Accord() = default;				// setting the default constructor
	Accord(string model, string color, float price);		// Accord constructor
	void menu() override;			 //override menu function from the vehicle class
};

Accord::Accord(string model, string color, float price) :Honda(model, color, price)		// inherits constructor function from vehicle class
{
	//empty
}

// Please see Toyota and Honda menu function commenting. Thank You.
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
		switch (a)
		{
		case '1':
			{
				a1.chosen();
				a1.discount();
			}break;
		case '2':
			{
				a2.chosen();
				a2.discount();
			}break;
		case '3':
			{
				a3.chosen();
				a3.discount();
			}break;
			case 'b': case 'B':
			{
				display();
			}break;
			case 'q':case 'Q':
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();
		}break;
	}
}

// 3rd level class: Civic class derived from Honda
// Please see Accord class and Honda menu function commenting. Thank You.
class Civic : public Honda
{
public:
	Civic() = default;
	Civic(string model, string color, float price);
	void menu() override;
};

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
		switch (a)
		{
		case '1':
			{
				c1.chosen();
				c1.discount();
			}break;
		case '2':
			{
				c2.chosen();
				c2.discount();
			}break;
		case '3':
			{
				c3.chosen();
				c3.discount();
			}break;
		case 'b': case 'B':
			{
				display();
			}break;
		case 'q': case 'Q':
			{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
			}break;
		default: menu();
		}break;
	}
}

// 3rd level class: City class derived from Honda
// Please see Accord class and Honda menu function commenting. Thank You.
class City : public Honda
{
public:
	City() = default;
	City(string model, string color, float price);
	void menu() override;
};

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
		switch(a)
		{
		case '1':
		{
			cty1.chosen();
			cty1.discount();
		}break;
		case '2':
		{
			cty2.chosen();
			cty2.discount();
		}break;
		case '3':
		{
			cty3.chosen();
			cty3.discount();
		}break;
		case 'b':case 'B':
		{
				display();
		}break;
		case 'q':case 'Q':
		{
				q = 2;
				cout << "\n\nProgram quitting...\n\n";
				break;
		}break;
		default: menu();
		}break;
	}
}
#endif // !Vehicle_Class_H