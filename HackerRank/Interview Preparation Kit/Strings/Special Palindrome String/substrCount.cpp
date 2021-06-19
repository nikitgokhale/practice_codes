#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    int sameCharCount[n] = {0};
    int resCount = 0;
    
    // Case 1: All of the characters are the same, e.g. aaa
    int i = 0, j/*The reference(forward) index*/, c; // Count of the characters;
    while (i < n) {
        j = i + 1, c = 1;
        while (j < n && s[i] == s[j]){
            ++j, ++c;
        }
        // Total substring with all the same character
        resCount += (c* (c + 1)) >> 1; // Divide by 2
        sameCharCount[i] = c;
        i = j;
    }
    
    // Case 2: All characters except the middle one are the same, e.g. aadaa
    for (j = 1; j < n-1; j++){
        if(s[j] == s[j-1]) {
            sameCharCount[j] = sameCharCount[j-1];
        }
        // The odd length substring which has middle element different
        if(s[j-1] == s[j+1] && s[j] != s[j-1]) {
            resCount += min(sameCharCount[j-1], sameCharCount[j+1]);
        }
    }
    return resCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
 