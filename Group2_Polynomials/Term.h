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
    friend bool operator == (const Term&, const Term&);

    Term& operator += (const Term&);

    // Class-member functions
    bool isZero() const;
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

// Equal-to operator
inline bool operator==(const Term& lhs, const Term& rhs) { return lhs.exponent == rhs.exponent; }

inline Term& Term::operator+=(const Term& rhs) {
    this->coefficient += rhs.coefficient;
    return *this;
}

// Check if the coefficient is zero
inline bool Term::isZero() const {
    return coefficient == 0;
}


#endif
