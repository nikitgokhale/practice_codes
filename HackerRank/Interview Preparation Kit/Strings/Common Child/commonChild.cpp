#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
/*
   We use 2-D Array here to get the longest count of the common subsequence
   2-D Array's size will be 1 more than the given string, i.e., A[0][0], 
   A[1][0] and A[0][1] will be initialized to 0
   1. Create a 2-D Array of 1 more size
   2. With two loops traverse the strings and compare the two strings letter by letter
      - If s1[i-1] == s2[j-1], then incrememt the position of i and j, taking the upper
      diagonal's variable
      - If not, inherit the max of the above and left side nodes from the 2-D arr
      - And initialize the position [1][0], [0][0] and [0][1] with 0
    The position [m][n] will contain the count of the longest common substring.
 */

static int T[5001][5001];

int commonChild(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                T[i][j] = 0;
            }
            else if (s1[i-1] == s2[j-1]) {
                T[i][j] = 1 + T[i-1][j-1];
            }
            else {
                T[i][j] = max(T[i][j-1], T[i-1][j]);
            }
        }
    }
    return T[m][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
