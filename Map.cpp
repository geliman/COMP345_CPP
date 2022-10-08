#include "Map.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::vector;


Map::Map() : nbTerr(new int(0)), nbCont(new int(0)),mapName(new string("default")){
	cout << "Map created" << endl;
};
Map::Map(int* nbT, int* nbC, string* mapN) : nbTerr(nbT), nbCont(nbC), mapName(mapN)
{
	
	cout << "Map created" << endl;
};

// copy constructor
Map::Map(const Map& map) : Map(map) {
	this->nbTerr = new int(*(map.nbTerr));
	this->nbCont = new int(*(map.nbCont));
	this->mapName = new string(*(map.mapName));
};

// assignment operator
Map& Map::operator=(const Map& map) {
	Map::operator=(map);
	this->nbTerr = new int(*(map.nbTerr));
	this->nbCont = new int(*(map.nbCont));
	this->mapName = new string(*(map.mapName));
	return *this;
}

// stream insertion operator
ostream& operator<<(ostream& out, const Map& map) {
	out << "Map name is " << *map.mapName << endl << "It has " << *map.nbCont << "continents" << endl << "and " << *map.nbTerr << "territories" << endl;
	return out;
}
Map::~Map() {
	delete nbTerr;
	nbTerr = nullptr;
	delete nbCont;
	nbCont = nullptr;
	delete mapName;
	mapName = nullptr;
}



void Map::setMapName(string* s) {
	delete mapName;
	mapName = s;

}
/// <summary>
/// Territory inner class constructor
/// </summary>
Map::Territory::Territory() {
	int* a = new int(0);
	string* o = new string("not owned");
	string* Tn = new string("");
	vector<Territory*>* adjT = new vector<Territory*>;
	nbArmies=a;
	owner=o;
	Tname = Tn;
	adjTerr=adjT;
};
// copy constructor
Map::Territory::Territory(const Territory& territory) {
	this -> nbArmies = new int(*(territory.nbArmies));
	this -> owner = new string(*(territory.owner));
	this -> Tname = new string(*(territory.Tname));
	this->adjTerr = new vector<Territory*>(*(territory.adjTerr));
	
};

// assignment operator
Map::Territory& Map::Territory::operator=(const Map::Territory& territory) {
	this->nbArmies = new int(*(territory.nbArmies));
	this->owner = new string(*(territory.owner));
	this->Tname = new string(*(territory.Tname));
	this->adjTerr = new vector<Territory*>(*(territory.adjTerr));
	return *this;
}

// stream insertion operator
ostream& operator<<(ostream& out, const Map::Territory& territory) {
	out << "Territory name is " << *territory.Tname << endl << "The owner is : " << *territory.owner << "continents" << endl << "and it has an army of size" << *territory.nbArmies << endl;
	return out;
	
}

Map::Territory::~Territory() {
	delete owner;
	owner = nullptr;
	delete nbArmies;
	nbArmies = nullptr;
	delete Tname;
	Tname = nullptr;
	delete adjTerr;
	adjTerr = nullptr;
	
}

/// <summary>
/// Continent inner class constructor
/// </summary>
Map::Continent::Continent() {
	string* Cn = new string("");
	int* cP = new int(0);
	vector<Territory*>* t = new vector<Territory*>;
	Cname = Cn;
	nbPts = cP;
	territories = t;
};
// copy constructor
Map::Continent::Continent(const Continent& continent) {
	this->Cname = new string(*(continent.Cname));
	this->nbPts = new int(*(continent.nbPts));
	this->territories = new vector<Territory*>(*(continent.territories));

};

// assignment operator
Map::Continent& Map::Continent::operator=(const Map::Continent& continent) {
	this->Cname = new string(*(continent.Cname));
	this->nbPts = new int(*(continent.nbPts));
	this->territories = new vector<Territory*>(*(continent.territories));
	return *this;
}

// stream insertion operator
ostream& operator<<(ostream& out, const Map::Continent& continent) {
	out << "Continent name is " << *continent.Cname << endl << "The player the owns the continent scores " << *continent.nbPts << " points" << endl << "and its territories are : insert territories iterator here" << endl;
	return out;
}

Map::Continent::~Continent() {
	delete Cname;
	Cname = nullptr;
	delete nbPts;
	nbPts = nullptr;
	delete territories;
	territories = nullptr;
}



