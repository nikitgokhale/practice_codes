#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void indexedPrinting(string s, int n)
{
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            cout << s[i];
        }
    }
    cout << " ";
    for (int i = 0; i < n; i++){
        if (i%2 != 0){
            cout << s[i];
        }
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        int n = s.length();
        indexedPrinting(s, n);
    }
    return 0;
}
