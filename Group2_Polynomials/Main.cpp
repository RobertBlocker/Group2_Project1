#include "Term.h"
#include "List.h"

#include <iostream>
#include <sstream>

using namespace std;

void menu();
void mainMenu();
Term create_term(string, int);
List<Term> create_list(string);
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
	string polyString1, polyString2;
	List<Term> poly1, poly2;

	do {
		mainMenu();

		switch (choice) {

		case 1:
			cout << "Enter first polynomial: " << endl;
			cin >> polyString1;
			poly1 = create_list(polyString1);
			break;

		case 2:
			cout << "Enter second polynomial: " << endl;
			cin >> polyString2;
			poly2 = create_list(polyString2);
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

void mainMenu() {

	cout << "Main Menu" << endl;
	cout << "1 - Enter 1st Polynomial" << endl;
	cout << "2 - Enter 2nd Polynomial" << endl;
	cout << "3 - Add Polynomials" << endl;
	cout << "4 - Quit" << endl;
	cout << "Please Enter (1, 2, 3, or 4): ";
	cin >> choice;
	cout << endl;

}

/** Creates a Term object given a string containing a polynomial term
 *	@param term: A string containing a polynomial term (2x^2)
 *	@param val: A value, either {1} or {-1} determining if the coefficient in positive or negative
 *	@return: A Term object with the coefficient and exponent of the value
 */
Term create_term(string term, int val) {
	string coeffString, expString;
	int i, coeff = 1, exp = 1;

	if (term.find('x') != string::npos) {
		for (i = 0; term[i] != 'x'; i++) {
			coeffString.push_back(term[i]);
		}

		if (term.find('^') != string::npos) {
			for (i = i + 2; i != term.size(); i++) {
				expString.push_back(term[i]);
			}
		}
	} else {
		coeffString = term;
		expString = "0";
	}

	if (!coeffString.empty()) {
		coeff = stoi(coeffString);
	}
	
	if (!expString.empty()) {
		exp = stoi(expString);
	}

	return Term(exp, coeff * val);
}

/** Creates a doubly-linked list given a polynomial string
 *	@param input: A string of a polynomial (5x^2+2x-10)
 *	@return: A doubly-linked list containing polynomial terms in each node
 */
List<Term> create_list(string input) {
	List<Term> poly;
	int c = 1; // Positive or negative

	while(!input.empty()) {
		// Check if the next term in positive or negative
		if (input[0] == '+') {
			c = 1;
			input.erase(0,1);
		} else if (input[0] == '-') {
			c = -1;
			input.erase(0,1);
		}

		size_t pos = input.find_first_of("+-");

		string termString = input.substr(0, pos);

		Term term = create_term(termString, c);
		poly.push_back(term);

		if (pos == string::npos) {
			break;
		}
		
		input.erase(0, pos);	
	}

	return poly;
}


void add_polynomials() {
	string poly1, poly2; 

	cout << poly1;
	cout << poly2;
	cout << "Added!" << endl;
}