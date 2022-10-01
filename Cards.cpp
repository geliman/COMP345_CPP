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
#include <string>
using namespace std;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;


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
class Deck;
class Player;

void Card::play(Deck *d, Player *p) {
  // cout << "Player is using " << p -> hand.card_type << endl;
}

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


void Deck::genDeck() {
  int v1;
  Card *c1 = new Card;
  string ct1 = "Bomb";
  c1->card_type = &ct1;

  Card *c2 = new Card;
  string ct2 = "Bomb";
  c2->card_type = &ct2;

  Card *c3 = new Card;
  string ct3 = "Bomb";
  c3->card_type = &ct3;

  Card *c4 = new Card;
  string ct4 = "Bomb";
  c4->card_type = &ct4;

  Card *c5 = new Card;
  string ct5 = "Bomb";
  c5->card_type = &ct5;
  for (int i = 0; i < 30; i++) {
    v1 = rand() % 5;
    if (v1 == 0) {
      deck.push_back(c1);
    } else if (v1 == 1) {
      deck.push_back(c2);
    } else if (v1 == 2) {
      deck.push_back(c2);
    } else if (v1 == 3) {
      deck.push_back(c3);
    } else if (v1 == 4) {
      deck.push_back(c4);
    } else {
      deck.push_back(c5);
    }
  }

  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  c1 = NULL;
  c2 = NULL;
  c3 = NULL;
  c4 = NULL;
  c5 = NULL;
}