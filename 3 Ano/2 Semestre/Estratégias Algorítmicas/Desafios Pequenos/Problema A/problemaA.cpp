#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    int n,m;

    getline(cin,input);


    stringstream ss(input);
    ss >> n >> m;

    int result = n * m;
    cout << result << endl;

    return 0;
}   