#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void isPrime(int N)
{
    if (N < 2){
        cout << "Not prime" << endl;
        return;
    }
    int n = sqrt(N);
    
    for (int i = 2; i <= n; i++){
        if ((N % i) == 0){
            cout << "Not prime" << endl;
            return;
        }
    }
    cout << "Prime" << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    
    while (t--){
        int N;
        cin >> N;
        isPrime(N);
    }
    return 0;
}
