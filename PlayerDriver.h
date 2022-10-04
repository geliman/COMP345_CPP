//#inlcude "Player.h"
#include <string>
#include <iostream>
using namespace std;

string testPlayers() {

    string returnStatement;

    //create test player(s)
    Player testPlayer1 = Player();

    //player.territories exists/is not empty
    if (testPlayer1.territories)
        returnStatement = returnStatement + "testPlayer1 has a list of territories";
    else
        returnStatement = returnStatement + "testPlayer1 does not have a list of territories";
    
    //player.cards exists/is not empty
    //player.toDefend returns list
    //player.toAttack returns list
    //player.issueOrder()

    return returnStatement;

}