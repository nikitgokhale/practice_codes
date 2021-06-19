#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    scanf("%d", &n);
    vector<vector<int>> arr;
    scanf("%d", &q);
    for(int i = 0; i < n; i++){
        int k;
        vector<int> v1;
        scanf("%d", &k);
        for(int l = 0; l < k; l++){
            int j;
            scanf("%d", &j);
            v1.push_back(j);
        }
        arr.push_back(v1);
    }
    
    int r, s;
    for(int a = 1; a <= q; a++){
        scanf("%d", &r);
        scanf("%d", &s);
        cout << arr[r][s] << endl;
    }
    return 0;
}