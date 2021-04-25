#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircaseL(int n) {
    int c = n-1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if (j < c){
                cout << " ";
            }
            else{
                cout << "#";
            }            
        }
        cout << endl;
        c = c-1;
    }
}

void staircaseR(int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i >= j){
                cout << "#";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircaseL(n);
    staircaseR(n);

    return 0;
}
