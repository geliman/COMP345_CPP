#include "Cards.h"
/**
 *
 * @author Giwon Lee - 40160453
 * @date 2022.10.2 Tuesday
 *
 */
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
string arr[30];
static int dynamicDeckSize = sizeDeck;

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

// void Card::play(Deck *d, Player *p) {
//   // cout << "Player is using " << p -> hand.card_type << endl;
// }

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

  for (int i = 0; i < sizeDeck; i++) {
    int v1 = rand() % 5;

    if (v1 == 0) {
      string s = "Bomb";
      deckArr[i] = s;
    } else if (v1 == 1) {
      string s1 = "Reinforcement";
      deckArr[i] = s1;
    } else if (v1 == 2) {
      string s2 = "Blockade";
      deckArr[i] = s2;
    } else if (v1 == 3) {
      string s3 = "Airlift";
      deckArr[i] = s3;
    } else {
      string s4 = "Diplomacy";
      deckArr[i] = s4;
    }
  }

  //   if (v1 == 0) {
  //     string s = "Bomb";
  //     Card c1;
  //     c1.setCard(s);
  //     deck.push_back(&c1);
  //   } else if (v1 == 1) {
  //     string s1 = "Reinforcement";
  //     Card c2;
  //     c2.setCard(s1);
  //     deck.push_back(&c2);
  //   } else if (v1 == 2) {
  //     string s2 = "Blockade";
  //     Card c3;
  //     c3.setCard(s2);
  //     deck.push_back(&c3);
  //   } else if (v1 == 3) {
  //     string s3 = "Airlift";
  //     Card c4;
  //     c4.setCard(s3);
  //     deck.push_back(&c4);
  //   } else {
  //     string s4 = "Diplomacy";
  //     Card c5;
  //     c5.setCard(s4);
  //     deck.push_back(&c5);
  //   }
  // }

  // for (int i = 0; i < sizeDeck; i++) {
  //   deckArr[i] = string(*deck.at(i)->card_type);
  // }

  cout << "Deck is Generated." << endl;
}

void Deck::displayDeck(string arr[]) {
  cout << "Deck has " << dynamicDeckSize << " cards:" << endl;
  for (int i = 0; i < dynamicDeckSize; i++) {
    cout << "\t" << i + 1 << ": " << arr[i] << endl;
  }
}

string Deck::draw() {
  if (dynamicDeckSize == 0) {
    cout << "Deck is empty now, you can no longer draw the cards" << endl;
    return NULL;
  }
  int v1 = rand() % dynamicDeckSize;
  cout << "At " << v1 << ": " << deckArr[v1] << endl;

  string tempCard = deckArr[v1];

  for (int i = 0; i < dynamicDeckSize - 1; i++) {
    deckArr[i] = deckArr[i + 1];
  }
  dynamicDeckSize--;
  return tempCard;
}

// --------------------------------------------------------------------------------
// Hand

// Default Constructor
Hand::Hand() {
  // cout << "Deck object" << endl;
}

Hand::~Hand() {
  // Default Destructor
}

// Copy Constructor
Hand::Hand(const Hand &h) {
  int size = sizeof(h.arrDec) / sizeof(string);
  for (int i = 0; i < size; i++) {
    this->arrDec[i] = h.arrDec[i];
  }
}

// Assignment Opeartor
Hand &Hand ::operator=(const Hand &h) {
  int size = sizeof(h.arrDec) / sizeof(string);
  for (int i = 0; i < size; i++) {
    this->arrDec[i] = h.arrDec[i];
  }
  return *this;
}
static int numCardsHand = 0;
void Hand::displayHandCards() {
  cout << "Hand object has Cards:" << endl;
  for (int i = 0; i < numCardsHand; i++) {
    cout << "\t" << i + 1 << " " << arrDec[i] << endl;
  }
}

void Hand::set_card(string s) {
  arrDec[numCardsHand] = s;
  numCardsHand++;
}

void Hand::displayNumOfCards() {
  cout << "Currently has " << numCardsHand << " cards." << endl;
}

void Hand::play(Deck *deck, string s, int index) {
  cout << "Your card is: " << s << endl;
  return_to_Deck(deck, s);
  arrDec[index] = "";
  for (int i = index; i < numCardsHand; i++) {
    if (index == numCardsHand) {
      numCardsHand--;
      return;
    }
    arrDec[i] = arrDec[i + 1];
  }
  numCardsHand--;
}

void Hand::return_to_Deck(Deck *deck, string s) {
  cout << "Card  " << s << " return back to the deck." << endl;

  deck->deckArr[dynamicDeckSize] = s;
  dynamicDeckSize++;
}

void testCards() {
  Deck d;

  d.genDeck();

  Hand h;
  int v1 = rand() % 10;
  for (int i = 0; i < v1; i++) {
    h.set_card(d.draw());
  }
  // d.displayDeck(d.deckArr);

  h.displayHandCards();

  // h.displayNumOfCards();
  while (true) {
    cout << "Which card do you want to play: " << endl;
    int index;
    cin >> index;

    h.play(&d, h.arrDec[index - 1], index - 1);
    break;
  }
  h.displayHandCards();
  // d.displayDeck(d.deckArr);
};