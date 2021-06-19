#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

const int CHARS = 26;
int makeAnagram(string a, string b) {
    int arr[CHARS] = {0};
    for (int i = 0; i < a.length(); i++) {
        arr[a[i] - 'a']++;
    }
    for(int i = 0; i < b.length(); i++){
        arr[b[i] - 'a']--;
    }
    
    long long int res = 0;
    for (int i = 0; i < CHARS; i++) {
        res += abs(arr[i]);
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
