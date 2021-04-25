#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // 1. Assemble a phone book that maps friends' names 
    //    to their respective phone numbers.
    int n;
    string name;
    long long int number;
    cin >> n;
    cin.ignore();
    map<string, long long int> phoneBook;
    for (int i = 0; i < n; i++){
        cin >> name;
        cin >> number;
        phoneBook[name] = number;
    }
    while (cin >> name){
        if(phoneBook.find(name) != phoneBook.end())
            cout << name << "=" << phoneBook.find(name)->second << endl;
        else 
            cout << "Not found" << endl;
    } 
    return 0;
}