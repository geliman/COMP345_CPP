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
#include <new>
#include <string>
// using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

// Default Constructor
Deck::Deck() {
  // cout << "Deck object" << endl;
  vector<Card *> deck;
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

vector<Card *> Deck::getDeck() { return deck; };

static vector<Card *> dd;
vector<Card *> Deck::genDeck() {
  int v1;

  for (int i = 0; i < 30; i++) {
    v1 = rand() % 5;

    if (v1 == 0) {
      string s = "Bomb";
      Card *c1 = new Card;
      c1->card_type = &s;
      Card ctemp;
      ctemp = *c1;
      deck.push_back(&ctemp);
      delete c1;
      c1 = NULL;
    } else if (v1 == 1) {
      string s2 = "Reinforcement";
      Card *c2 = new Card;
      c2->card_type = &s2;
      Card ctemp;
      ctemp = *c2;
      deck.push_back(&ctemp);
      delete c2;
      c2 = NULL;
    } else if (v1 == 2) {
      string s3 = "Blockade";
      Card *c3 = new Card;
      c3->card_type = &s3;
      Card ctemp;
      ctemp = *c3;
      deck.push_back(&ctemp);
      delete c3;
      c3 = NULL;
    } else if (v1 == 3) {
      string s4 = "Airlift";
      Card *c4 = new Card;
      c4->card_type = &s4;
      Card ctemp;
      ctemp = *c4;
      deck.push_back(&ctemp);
      delete c4;
      c4 = NULL;
    } else {
      string s5 = "Diplomacy";
      Card *c5 = new Card;
      c5->card_type = &s5;
      Card ctemp;
      ctemp = *c5;
      deck.push_back(&ctemp);
      delete c5;
      c5 = NULL;
    }
  }
  dd = deck;
  for (int i = 0; i < deck.size(); i++) {
    cout << i + 1 << ": " << string(*deck.at(i)->card_type) << endl;
  }

  cout << "Deck is Created" << endl;
  return deck;
}

// void displayDeck() {
//   cout << deck.size();
//   for (int i = 0; i < deck.size(); i++) {
//     cout << i + 1 << ": " << string(*deck.at(i)->card_type) << endl;
//   }
// }

int main() {

  Deck *d = new Deck();
  Deck *de = new Deck();
  d->genDeck();
  cout << string(*dd.at(0)->card_type);

  // cout << string(*de.at(3)->card_type);

  // d->displayDeck();

  // displayDeck(d);
  // cout << string(*d->deck.at(0)->card_type);

  return 0;
}