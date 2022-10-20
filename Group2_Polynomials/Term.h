#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <string>

using namespace std;

class Term {
public:
    
    // Default Constructor
    Term(int, int);

    // Operators
    friend bool operator < (const Term&, const Term&);
    friend bool operator > (const Term&, const Term&);
private:
    // Data fields
    int exponent, coefficient;
};

// Default Constructor
inline Term::Term(int exp, int coeff) : exponent(exp), coefficient(coeff) {}

// Less-Than Operator
inline bool operator<(const Term& lhs, const Term& rhs) { return lhs.exponent < rhs.exponent; }

// Greater-Than Operator
inline bool operator>(const Term& lhs, const Term& rhs) { return rhs < lhs; }


#endif
