
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {

    ifstream file("./maps/Grand Montreal.map");
    string str;
    vector<vector<string>> arr_cont; /* [i][0]  -> continents ; [i][n] -> n > 0, Territoires d'un continent 'i' */
    

    while (getline(file, str)) {

        if (str == "[Continents]") {

            while (getline(file, str) && str != "[Territories]") {
                if (str != "" && str != "\n") {
                    vector<string> temp;
                    temp.push_back(str);
                    arr_cont.push_back(temp);
                }
                

            }
            /* end of continents array */
        }
       
            

        if (str == "[Territories]"){
            int index = 0;
            
                while (getline(file, str)) {
                    if (str != "" && str != "\n") {
                        arr_cont.at(index).push_back(str);
                    }
                    else {
                        index++;
                    }
                }
            
            
        }
        for (int i = 0; i < arr_cont.size(); i++) {

            cout << "Continent" << i+1 << " : " << arr_cont.at(i).at(0) << "\n\n";

            for (int j = 1; j < arr_cont.at(i).size(); j++) {

                cout << "Territoire" << j << " : " << arr_cont.at(i).at(j) << "\n";

            }
            cout << "\n";
        }

    }
    
    return 0;
}