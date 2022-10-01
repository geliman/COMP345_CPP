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
    this -> name = new string(*(e.name))
    this -> num = new int(*(e.num))
    this -> pay = new double(*(e.pay))
    return *this;
}

copy consturtor e.g
in class
Employee(const Employee &e);
method
Employee::Employee(const Employee&e){
    this -> name = new string(*(e.name))
    this -> num = new int(*(e.num))
    this -> pay = new double(*(e.pay))
}

5. Memory leaks must be avoided.
Use delete
~A(){};

6. Code must be documented using comments (user-defined classes, methods, free
functions, operators).

*/

#include "Cards.h"
using std::cout;
using std::endl;
using std::vector;

// Default Constructor
Deck::Deck() { cout << "Deck object" << endl; }
Deck::~Deck() {
  // Default Destructor
}
// Copy Constructor
Deck::Deck(const Deck &d) { this->deck = *new vector<Card *>(d.deck); }
// Assignment Opeartor
Deck &Deck ::operator=(const Deck &d) {
  this->deck = *new vector<Card *>(d.deck);
  return *this;
}
// Stream insertion operator
std::ostream &operator<<(std::ostream &os, const Deck &d) {
  cout << "How many cards are in a deck: " << endl;
  return os << d.deck.capacity() << endl;
}
void Deck::genDeck(){

}





// Default Constructor
Card::Card() {
  cout << "Card object" << endl;
  card_type = NULL;
}
// Default Destructor
Card::~Card() {}

// Copy Constructor
Card::Card(const Card &c) { this->card_type = new string(*(c.card_type)); }

// Assignment operators
Card &Card ::operator=(const Card &c) {
  this->card_type = new string(*(c.card_type));
  return *this;
}

// Stream insertion operator
std::ostream &operator<<(std::ostream &os, const Card &c) {
  return os << "The card type is: " << c.card_type << endl;
}

class Player;

void Card::play(Deck *d, Player *p) {
  // cout << "Player is using " << p -> hand.card_type << endl;
}

int main() {

  Deck *deck = new Deck();

  deck->genDeck();
  return 0;
}
