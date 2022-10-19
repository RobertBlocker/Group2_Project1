
#include "D_Node.h"
#include "List.h"

#include <iostream>
#include <cstdlib>

using namespace std;

void menu();
void mainMenu();
void add_polynomials();
int choice = 0;

int main(int argc, char** argv)
{
	menu();

	return 0;
}

/** Menu for choosing to enter polynomials, add polynomials, and exit
*	Switch through case 1 - 4.
*/
void menu() {
	string poly1, poly2;

	do {
		mainMenu();

		switch (choice) {

		case 1:
			cout << "Enter first polynomial: " << endl;
			cin >> poly1;
			cout << endl;
			break;

		case 2:
			cout << "Enter second polynomial: " << endl;
			cin >> poly2;
			cout << endl;
			break;

		case 3: 
			add_polynomials();
			cout << endl;
			break;

		case 4:
			break;
		}//end of switch
		
	} while (choice != 4);
}//end of menu

void mainMenu(void) {

	cout << "Main Menu" << endl;
	cout << "1 - Enter 1st Polynomial" << endl;
	cout << "2 - Enter 2nd Polynomial" << endl;
	cout << "3 - Add Polynomials" << endl;
	cout << "4 - Quit" << endl;
	cout << "Please Enter (1, 2, 3, or 4): ";
	cin >> choice;
	cout << endl;

}

void add_polynomials(void) {
	string poly1, poly2; 

	cout << poly1;
	cout << poly2;
	cout << "Added!" << endl;
}