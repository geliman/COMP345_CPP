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
using std::string;
using std::vector;
string arr[20];


// --------------------------------------------------------------------------------
// Card
// Default Constructor
Card::Card() {
  // cout << "Card object" << endl;
}
// Default Destructor
Card::~Card() {}

Card::Card(string s) { *card_type = s; }

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

string *Card::getCard() { return this->card_type; }

class Deck;
class Player;

void Card::setCard(string s) { this->card_type = &s; }
void Card::play(Deck *d, Player *p) {
  // cout << "Player is using " << p -> hand.card_type << endl;
}

// --------------------------------------------------------------------------------
// Deck

// Default Constructor
Deck::Deck() {
  // cout << "Deck object" << endl;
}

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
  int v1 = -1;

  for (int i = 0; i < 30; i++) {
    v1 = rand() % 5;

    if (v1 == 0) {
      string s = "Bomb";
      Card c1;
      c1.setCard(s);
      deck.push_back(&c1);
    } else if (v1 == 1) {
      string s1 = "Reinforcement";
      Card c2;
      c2.setCard(s1);
      deck.push_back(&c2);
    } else if (v1 == 2) {
      string s2 = "Blockade";
      Card c3;
      c3.setCard(s2);
      deck.push_back(&c3);
    } else if (v1 == 3) {
      string s3 = "Airlift";
      Card c4;
      c4.setCard(s3);
      deck.push_back(&c4);
    } else {
      string s4 = "Diplomacy";
      Card c5;
      c5.setCard(s4);
      deck.push_back(&c5);
    }
  }

  for (int i = 0; i < 20; i++) {
    deckArr[i] = string(*deck.at(i)->card_type); 
  }
  
  cout << "Deck is Generated." << endl;
}

void Deck::displayDeck( string arr[]) {
  for (int i = 0; i < 20; i++) {
    cout << i + 1 << " " << arr[i] << endl;
  }
}

int main(){

  Deck d;
  d.genDeck();
  d.displayDeck(d.deckArr);
  
  return 8;
}