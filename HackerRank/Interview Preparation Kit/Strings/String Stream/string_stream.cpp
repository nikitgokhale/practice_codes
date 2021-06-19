#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> res;
    stringstream ss(str);
    int n; // To store individual numbers
    char ch; 
    while(ss >> n){
        res.push_back(n);   // pushing only the integer value
        ss >> ch;           // trimming the ','
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}