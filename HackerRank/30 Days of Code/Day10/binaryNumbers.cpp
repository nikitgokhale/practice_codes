#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int count = 0;
    int max = 0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while (n){
        if (n&1) {
            count++;
        }
        else{
            count = 0;
        }
        if (max < count) {
            max = count;
        }
        n>>=1;
    }
    cout << max << endl;

    return 0;
}
