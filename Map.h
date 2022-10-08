#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

class Map
{
public:


	 // default constructor
	Map() {};
	Map(int *nbT, int *nbC, string *mapN){};
        // copy constructor
	Map(const Map& map){};

        // assignment operator
        Map& operator =(const Map& map);

        // stream insertion operator
        friend ostream& operator <<(ostream& out, const Map& map);

        // Destructor
		~Map() {};


		

	class Territory {
	public:
		// default constructor
		Territory();

		// copy constructor
		Territory(const Territory& territory);

		// assignment operator
		Territory& operator=(const Territory& territory);

		// stream insertion operator
		friend ostream& operator<<(ostream& out, const Territory& territory);

		// Destructor
		~Territory();

		pair<int*, int*>* getCoord();
		string* getOwner() ; /* must change to player*/
		int* getNbArmies() ;

		vector<Territory*>* getAdjacentTerritories();
		string* getName();

		int* nbArmies;
		string* owner;
		string* Tname;

		
		vector<Territory*>* adjTerr;
	};

	class Continent {
	public:
		// default constructor
		Continent();

		// copy constructor
		Continent(const Continent& continent);

		// assignment operator
		Continent& operator=(const Continent& continent);

		// stream insertion operator
		friend ostream& operator<<(ostream& out, const Continent& continent);

		// Destructor
		~Continent();

		string* getName();
		int* getNbPts();


		string* Cname;
		int* nbPts;
		vector<Territory*>* territories;
	};
	


	/*Continent getContinent(Continent continent) const;*/
	int* getNbContinents();
	int* getNbTerritories(Continent* continent);
	void setMapName(string* input) {};
	/*vector<string> getTerritories(Continent continent) const; */
	

	

	static bool validateMap(); /* Safeguard here */


	private:
	int* nbTerr;
	int* nbCont;
	string* mapName;




};