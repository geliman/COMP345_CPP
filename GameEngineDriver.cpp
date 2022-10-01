#include "GameEngine.h"



int main() {

    GameEngine engine = GameEngine();
    string input;
    string last;
    cout << "---------Please enter new input------------" << endl;

    while (cin >> input) {
        if (! input.compare("end") && ! last.compare("win")) {
            engine.~GameEngine();
            cout << "You have ended the game" << endl;
            break;
        }

        engine.changeState(&input);
        cout << "---------Please enter new input------------" << endl;
        last = input;
    }
}