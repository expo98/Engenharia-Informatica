#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main(){
    vector<int> array;
    int num;

    while (cin >> num)
    {
        
        array.push_back(num);
    }

    sort(array.begin(),array.end());


    for (size_t i; i < array.size(); i++)
    {   
        cout << array[i] << "\n";
    }

    return 0;
}