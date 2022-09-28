#include "GameEngine.h"



int main() {

    GameEngine engine = GameEngine();
    string input;

    cout << "Please enter new input" << endl;
    while (cin >> input) {
        engine.changeState(&input);
        cout << "Please enter new input" << endl;
    }
}