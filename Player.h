#pragma once

#include "Cards.h"
#include "Map.h"
#include "Order.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Player
{
    public:
        Player(); //default constructor
        ~Player(); //destructor
        Player(string playerName, vector<Map::Territory*> territoriesOwned, vector<Card*> playerHand, vector<Order*> ordersIssued);
        Player(const Player&); //copy constructor
        

        //Data members
        string* name;
        vector<Map::Territory*> *territory;
        vector<Card*> *hand;
        vector<Order*> *orders;

        void toDefend(); 
        void toAttack();
        void issueOrder();

        //vector<Map::Territory*> *defenceList;
        //vector<Map::Territory*> *attackList;
};

string testPlayers();
