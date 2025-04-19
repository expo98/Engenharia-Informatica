#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    vector<int> list = {0};
    int ponteiro = 0; // Define a posição na lista onde o ponteiro está
    
    string line;
    
    
    while (getline(cin,line))
    {
        stringstream ss(line);
        string command, direction;
        int value;

        ss >> command;

        if (command == "MOVE")
        {
            ss >> direction;
            if (direction == "LEFT")
            {
                ponteiro--;
            }
            else if (direction == "RIGHT")
            {
                ponteiro++;
            }
            
        }

        else if (command == "INSERT")
        {
            ss >> direction;
            if (direction == "LEFT")
            {
                ss >> value;
                list.insert(list.begin() + ponteiro, value );
                ponteiro++;
            }
            else if (direction == "RIGHT")
            {
                ss >> value;
                list.insert(list.begin() + ponteiro + 1, value);
            }
        }
        
        
    }

    for (int num: list)
    {
        cout << num << "\n";
    }
    
 
    return 0;
}