#include "Cards.h"
using namespace std;
int main() {

  Deck d;

  d.genDeck();

  Hand h;

  for (int i = 0; i < 15; i++) {
    h.set_card(d.draw());
  }
  // d.displayDeck(d.deckArr);

  h.displayHandCards();

  // h.displayNumOfCards();
  while (true) {
    cout << "Which card do you want to play: " << endl;
    int index;
    cin >> index;
    h.play(&d, h.arrDec[index], index);
    break;
  }
  h.displayHandCards();
  d.displayDeck(d.deckArr);
  return 0;
}