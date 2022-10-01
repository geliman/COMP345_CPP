#include <iostream>
#include <string>
#include <fstream>
#include <vector>



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
		vector<Territory> getAdjacentTerritories(Territory territory) const;

	};
	class Continent {
	public:
		Continent();
		Continent(vector<Territory> arr_territories);
		string getData();
		
	};
	
	
	Continent getContinent(Continent continent) const;
	int getNbContinents() const;
	int getNbTerritories(Continent continent) const;
	vector<string> getTerritories(Continent continent) const;
	
private:
	static bool validateMap() const; /* Safeguard here */
};