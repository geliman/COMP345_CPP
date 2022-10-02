
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int testLoadMaps() {

    string str;
    vector<vector<string>> arr_cont; /* [i][0]  -> continents ; [i][n] -> n > 0, Territoires d'un continent 'i' */
    ifstream file("./maps/Grand Montreal.map");

    while (getline(file, str)) {

        if (str == "[Continents]") {

            while (getline(file, str) && str != "[Territories]") {
                if (str != "" && str != "\n") {
                    int found;

                    string temp2;
                    vector<string> temp;
                    string delimiter = "=";


                    temp2 = str.substr(0, str.find(delimiter));
                    temp.push_back(temp2);
                    temp2 = str.substr(str.find(delimiter) + 1, str.length() - 1); 
                    temp.push_back(temp2);
                    arr_cont.push_back(temp);
                }
                

            }
            /* end of continents array */
        }
       
            

        if (str == "[Territories]"){
            int index = 0;
            string delimiter2 = ",";
            string terrName;
            string terrProperties;

                while (getline(file, str)) {
                    if (str != "" && str != "\n") {
                        terrName = str.substr(0, str.find(delimiter2));
                        terrProperties = str.substr(str.find(delimiter2) + 1, str.length() - 1);
                        arr_cont.at(index).push_back(terrName);
                        arr_cont.at(index).push_back(terrProperties);
                        

                    }
                    else {
                        index++;
                    }
                }
        }
        for (int i = 0; i < arr_cont.size(); i++) {

            cout << "Continent #" << i + 1 << " : " << arr_cont.at(i).at(0) << "\n\n";
            cout << "Points" << " : " << arr_cont.at(i).at(1) << "\n\n";
            for (int j = 2; j < arr_cont.at(i).size(); j+=2) {
                /* j = territory name; j+1 = territory properties */
                cout << "Territory #" << j-1 << " : " << arr_cont.at(i).at(j) << "\n";
                cout << "Territory properties :" << arr_cont.at(i).at(j+1) << "\n\n";
            }
            
            cout << "\n******************************\n";
        }

    }
    file.close();
    return 0;
}


int main() {
    
    testLoadMaps();
    cout << "Okay";
    return 0;

}