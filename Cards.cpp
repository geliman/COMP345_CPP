/**
 1. All data members of user-defined class type must be of pointer type.

no inline function

4. All classes must implement a correct copy constructor, assignment operator,
and stream insertion operator.

Assignment operators
in class
Employee& operator =(const Employee & e);
method
Employee &Employee:: operator(const Employee&e){
    this -> name = new string(*e(e.name))
    this -> num = new int(*e(e.num))
    this -> pay = new double(*e(e.pay))
    return *this;
}

copy consturtor e.g
in class
Employee(const Employee &e);
method
Employee::Employee(const Employee&e){
    this -> name = new string(*e(e.name))
    this -> num = new int(*e(e.num))
    this -> pay = new double(*e(e.pay))
}

5. Memory leaks must be avoided.
Use delete
~A(){};

6. Code must be documented using comments (user-defined classes, methods, free
functions, operators).

*/

#include "Cards.h"


