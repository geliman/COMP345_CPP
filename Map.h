#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Map
{
public:
	Map();
	Map(vector<vector<string>> arr_continent); /* double vector for array of continents */

	class Territory {
	public:
		Territory();
		Territory(string territory);
		string getData();
		string* getOwner(); /* must change to player*/
		int getNbArmies();
		vector<Territory> getAdjacentTerritories();
		int nbArmies;
		string owner;
		string data;
		vector<Territory> adjTerr;
	};

	class Continent {
	public:
		Continent();
		Continent(vector<Territory> arr_territories);
		string getData();
		
	};
	


	/*Continent getContinent(Continent continent) const;*/
	int getNbContinents();
	int getNbTerritories(Continent continent);
	/*vector<string> getTerritories(Continent continent) const; */
	
private:
	int nbTerr;
	int nbCont;
	string mapName;

	static bool validateMap(); /* Safeguard here */
};