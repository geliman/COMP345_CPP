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
  // -------------startup-------------------  
  if (*curr_state == "start") {
    if (*input == "loadmap") {
      //loadMap();
      setState(new string("map loaded"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  } else if (*curr_state == "map loaded") {
    if (*input == "loadmap") {
      //loadMap();
      setState(new string("map loaded"));
    } else if (*input == "validatemap") {
      //validateMap();
      setState(new string("map validated"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  } else if (*curr_state == "map validated") {
    if (*input == "addplayer") {
      //addPlayer();
      setState(new string("players added"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  } else if (*curr_state == "players added") {
    if (*input == "addplayer") {
      //addPlayer();
      setState(new string("players added"));
    } else if (*input == "assigncountries") {
      //assignReinforcement();
      setState(new string("assign reinforcement"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  // -------------play-------------------  
  } else if (*curr_state == "assign reinforcement") {
    if (*input == "issueorder") {
      //issue_order();
      setState(new string("issue orders"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  } else if (*curr_state == "issue orders") {
    if (*input == "issueorder") {
      //issue_order();
      setState(new string("issue orders"));
    } else if (*input == "endissueorders") {
      //endIssueOrders();
      setState(new string("execute orders"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  } else if (*curr_state == "execute orders") {
    if (*input == "execorder") {
      //execOrder();
      setState(new string("execute orders"));
    } else if (*input == "endexecorders") {
      //assignReinforcement();
      setState(new string("assign reinforcement"));
    } else if (*input == "win") {
      //win();
      setState(new string("win"));
    }else {
       cout << "You have entered an invalid command" << endl;
    }
  } else if (*curr_state == "win") {
    if (*input == "play") {
      //start();
      setState(new string("start"));
    } else {
       cout << "You have entered an invalid command" << endl;
    }
  }




}

