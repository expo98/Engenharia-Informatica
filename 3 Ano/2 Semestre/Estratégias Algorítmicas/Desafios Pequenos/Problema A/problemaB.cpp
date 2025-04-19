#include <iostream>
#include <string>
#include <sstream>

using namespace std;


#define ARRAYSIZE 1000

int main(){

    int array[ARRAYSIZE];

    string stringInput;
    int inputSize;


    getline(cin, stringInput);
    stringstream ss(stringInput);
    ss >> inputSize;

    getline(cin, stringInput);
    stringstream ss2(stringInput);

    for (int i = 0; i < inputSize; i++)
    {
        ss2 >> array[i];
    }
    


    for (int i = 0; i < inputSize/2; i++)
    {
        int temp = array[i];
        array[i] = array[inputSize-1-i];
        array[inputSize-1-i] = temp;
    }

    for (int i = 0; i < inputSize; i++)
    {
        if (i == inputSize -1)
        {
            cout << array[i];
        }
        else 
        {
            cout << array[i] << " ";
        }
        
    }
    cout << endl;
    
    return 0;
}