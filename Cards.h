#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using std::ostream;
using std::string;
using std::vector;

// Declaration of deck size, deck contains 25 cards.
const int sizeDeck = 25;
class Card
{
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

  // returns a card.
  string *getCard();
  void setCard(string s);
  string *card_type;
};

class Deck : public Card
{

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
  // This array is used as a pointer in CPP file.
  string arrDeck[sizeDeck];
  vector<Card *> deck;
};

class Hand : Deck
{

public:
  Hand();
  ~Hand();

  // assignment operator
  Hand &operator=(const Hand &h);

  // copy constructor
  Hand(const Hand &h);

  // Stream insertion operator
  friend ostream &operator<<(ostream &out, const Hand &Hand);

  // Set a card to hand when draw happens.
  void set_card(string);

  // Display how many cards you have in hand
  void displayNumOfCards();

  // Display cards that are in the hand.
  void displayHandCards();

  // Takes one of the cards in the hand and returns to the Deck.
  void play(Deck *deck, string s, int index);

  // Returns a card to the Deck.
  void return_to_Deck(Deck *deck, string s);

  // This array is used as a pointer in CPP file.
  string arrHand[sizeDeck];
};


// A free function to visualize the functionality of the code.
void testCards();
