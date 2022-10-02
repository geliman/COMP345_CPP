#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using std::cin;
using std::ostream;
using std::string;
using std::vector;
const int sizeDeck = 30;
class Card {
  class Deck;

public:
  Card();
  ~Card();
  Card(string s);
  // assignment operator
  Card &operator=(const Card &c);

  // Copy constructor
  Card(const Card &c);

  // Stream insertion operator
  friend ostream &operator<<(ostream &out, const Card &Card);

  // void play(Deck *deck);
  string *getCard();
  void setCard(string s);
  string *card_type;

  // Each card has a type from: bomb, reinforcement, blockade, airlift, and
  // diplomacy.

  // vector<string> type_card = {"Bomb", "Reinforcement", "Blockade", "Airlift",
  //                             " Diplomacy"};

  // Vector gives me a red line saying "
  // Non-aggregate type 'vector<std::string>'(aka 'vector<basic_string<char,
  // char_traits<char>, allocator<char> > >') cannot be initialized with an
  // initializer list"
  // Seems like a common problem for c++ 11.
  // You can run the code with  =>      g++ -std=c++ <filename>
  // Complies with no problem
};

class Deck : public Card {
  Card *card;

public:
  string draw();

  Deck();
  ~Deck();
  Deck(Card *card);
  // assignment operator
  Deck &operator=(const Deck &d);

  // copy constructor
  Deck(const Deck &d);

  // Stream insertion operator
  friend ostream &operator<<(ostream &out, const Deck &Deck);

  // Deck will be generated with this method.
  void genDeck();

  // Display the deck
  void displayDeck(string arr[]);

  // The deck that will contain cards.
  string deckArr[sizeDeck];
  vector<Card *> deck;
};

class Hand : Deck {

public:
  Hand();
  ~Hand();

  // assignment operator
  Hand &operator=(const Hand &h);

  // copy constructor
  Hand(const Hand &h);

  // Stream insertion operator
  friend ostream &operator<<(ostream &out, const Hand &Hand);

  void set_card(string);
  void displayNumOfCards();
  void displayHandCards();
  void play(Deck *deck, string s, int index);
  void return_to_Deck(Deck *deck, string s);
  string arrDec[sizeDeck];
};

void testCards();