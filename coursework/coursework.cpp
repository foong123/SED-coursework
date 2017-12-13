/*	I have chosen vehicle to be my theme of this SED coursework. To be more specific, 
	this vehicle will be more specific on car brands. I have added with some "fancies" functions so
	that it will "beautify" the overall program. I will try my best to explain them in details as possible. Thank You. */

#include <iostream>
#include <string>
#include <cstdlib>							
#include <time.h>												
#include <iomanip>
#include "Vehicle_Class.h"
using namespace std;
void display();				// initialize a main menu function
int coupon();				// initialize a coupon function

/*	Before explaining the display function(below),I would like to state that I have not follow one the instrustions 
	in the SED Coursework instruction which says the main function must consists of arrays of pointers of 
	base class. I chose not to do so because I need this display function so that the coupon function can use
	this display function */

//display function
void display() 
{
	Vehicle arr_vehicle[100];			// creates an array of pointers for the base class
	Vehicle vehicle;
	Toyota toyota;
	Honda honda;
	Camry camry;
	Altis altis;
	Vios vios;
	Accord accord;
	Civic civic;
	City city;
	arr_vehicle[0] = vehicle;			// assigning the arrays into arrays of vehicle
	arr_vehicle[1] = toyota;
	arr_vehicle[2] = honda;
	arr_vehicle[3] = camry;
	arr_vehicle[4] = altis;
	arr_vehicle[5] = vios;
	arr_vehicle[6] = accord;
	arr_vehicle[7] = civic;
	arr_vehicle[8] = city;
	Vehicle* option;					//  the array is pointed to the option
	int i = 1;							// Initialize and declare i = 1 for the looping
	char a;
	while (i == 1)						// This will print the main menu of the program 
	{
		cout << "Please select one: \n\n";
		cout << "========== MAIN MENU ==========\n" << "'1' - General Vehicles\n" << "'2' - Special Toyota Cars\n";
		cout << "'3' - Toyota Camry\n" << "'4' - Toyota Altis\n";
		cout << "'5' - Toyota Vios\n" << "'6' - Special Honda Cars\n";
		cout << "'7' - Honda Accors\n" << "'8' - Honda Civic\n";
		cout << "'9' - Honda City\n";
		cout << "'q' - Quit program\n" << "--------------------------\n" << ">>";
		cin >> a;
		cin.ignore(256, '\n');			// This is to read the first character of a and ignore the rest
		switch (a)						// Evaluating from the first character of a
		{
		case '1':
		{
			option = &vehicle;			/*demonstrating polymorphism by looping through the base pointer array 
										and calling menu function*/
			option->menu();
		}break;							
		case '2':
		{
			option = &toyota;			// similar explanation for case '1'
			option->menu();
		}break;
		case '3':
		{
			option = &camry;			// similar explanation for case '1'
			option->menu();
		}break;
		case '4':
		{
			option = &altis;			// similar explanation for case '1'
			option->menu();
		}break;
		case '5':
		{
			option = &vios;				// similar explanation for case '1'
			option->menu();
		}break;
		case '6':
		{
			option = &honda;			// similar explanation for case '1'
			option->menu();
		}break;
		case '7':
		{
			option = &accord;			// similar explanation for case '1'
			option->menu();
		}break;
		case '8':
		{
			option = &civic;			// similar explanation for case '1'
			option->menu();
		}break;
		case '9':
		{
			option = &city;				// similar explanation for case '1'
			option->menu();
		}break;
		case 'q': case 'Q':				// To end the program 
		{
			i = 2;
			cout << "\n\nProgram quitting...\n\n";
		}break;
		default: display();			//If user enter random characters apart from the switch case it will shows display function 
		}break;
	}
}

//
/*	This coupon function is design to generate a random number so that when
	the user enter the coupon number will be different on calling the function.
	This will prevents cheating :) */

// coupon function
int coupon()
{
	srand(time(0));							// seeds the pseudo random generator used by the rand function
	int number;
	number = rand() % 10 + 1;				//returns a random number from a range of modulo of 10. It will have a range of 1-10
	int tries = 3;							// User is given 3 tries
	int guess;								// User guess on the coupon
	cout << "Coupon codes is valid between 1-10" << endl;
	do {											// It will loop until tries used up or the user guessed correct
		cout << "You have " << tries << " tries remaining\n\n";		// Stating the number of tries
		cout << "Enter your coupon: " << endl;
		cin >> guess;
		tries--;											// decrease in tries count
		if (tries <= 0)
		{
			break;											// the loop will break once the tries is used up
		}
		else if (guess < number)							// check if the guess is same as the generated number
		{
			cout << "Invalid Coupon...\n\n" << endl;
		}
		else if (guess > number)							// check if the guess is same as the generated number
		{
			cout << "Invalid Coupon...\n\n" << endl;
		}
	} while (guess != number);								// End of loop once guessed correctly
	if (guess == number)									// Check if user guessed correctly
	{
		cout << "Congratulations you have enter the correct coupon!\n" << endl;		// Display Joyfulness :) 
	}
	else
	{
		cout << "Sorry you have enter the wrong coupon\n\n";	// display unsuccessful guess :(
		display();												// return to main menu
		system("pause");										//	hold the console
		exit(0);					
		/*	Exit function from the header file and return a new display function. It is like creating a new 
			display for the user after unsuccessful attempt getting the coupon. */
	}
	tries = 0;		// declare tries = 0 after all the looping is done
}

int main()
{
	string name;										// initialize name as a string
	cout << "Enter name please\n>> ";
	getline(cin, name);									// get the name of the user with spacing
	cout << "\nHello Mr." << name << endl << endl;
	display();											// call the display function
	system("pause");
	return 0;
}