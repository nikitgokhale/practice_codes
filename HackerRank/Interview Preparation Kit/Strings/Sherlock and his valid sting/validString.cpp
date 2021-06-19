#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
const int CHARS = 26;
string isValid(string s) {
    int arr[CHARS] = {0};
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'a']++;
    }
    int max = -1;
    bool removed_flag = false;
    for (int i = 0; i < CHARS; i++) {
        if (arr[i] == 0)
            continue;
        else if (max == -1){
            max = arr[i];
            continue;
        }
        else if (arr[i] == max)
            continue;
        else if (!removed_flag && (arr[i] == max + 1 || arr[i] == 1)) {
            removed_flag = !removed_flag;
            continue;
        }
        else
            return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
