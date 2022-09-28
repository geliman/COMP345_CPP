#include "GameEngine.h"
#include <string>

using namespace std;


// bool State::check_valid_transit(string new_input) {
//   if (state == "start") {
//       if (new_input == "loadmap") {

//       }
//   }

// }

GameEngine::GameEngine() {
  string * str = new string("start");
  setState(str);
}

GameEngine::~GameEngine() {

}

string * GameEngine::getState() {
  return curr_state;
}
void GameEngine::setState(string * new_state) {
  curr_state = new_state;
  cout << "State set to " << * new_state << endl;
}


void GameEngine::changeState(string * input) {

  if (*curr_state == "start") {
    cout << "Current state is start" << endl;
    if (*input == "loadmap") {
      //loadMap();
      cout << "Map has been loaded" << endl;
      setState(new string("loadmap"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  }

  if (*curr_state == "loadmap") {
    cout << "Current state is load map" << endl;
    if (*input == "loadmap") {
      //loadMap();
      cout << "Map has been loaded" << endl;
      setState(input);
    }  else if (*input == "validatemap") {
      //validateMap();
      cout << "Map has been validated" << endl;
      setState(input);
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  }

  if (*curr_state == "validatemap") {
    cout << "Current state is validate map" << endl;
    if (*input == "addplayer") {
      //addPlayer();
      cout << "Player has been added" << endl;
      setState(input);
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  }

  if (*curr_state == "addplayer") {
    if (*input == "assigncountries") {
      //addPlayer();
      cout << "Player has been added" << endl;
      setState(input);
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  }

}

