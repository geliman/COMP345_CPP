
#include <iostream>
#include <string>

using namespace std;


class GameEngine {
    
    private:
        string * curr_state;

    public:
        // default constructor
        GameEngine();
        // copy constructor
        GameEngine(const GameEngine& state);
        // assignment operator
        GameEngine& operator=(const GameEngine& state);
        // stream insertion operator
        friend ostream& operator<<(ostream& out, const GameEngine& GameEngine);
        // Destructor
        ~GameEngine();
        //
        void startUp();
        void play();
        void changeState(string * input);

        string * getState();
        void setState(string * new_state);

};
