#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */
// Algorithm basically boils down to cleverly applying modulo. We know that no 2 elements can be
// divisible by k, which also means the mod(k) of no two numbers can sum to k. For example with 
// k = 10, we can't have two numbers where first_number%k = 1 and second_number%k = 9, since those 
// would sum to a multiple k. Thus we'll either take all of the numbers whose value mod k is 1, or 
// all of the numbers whose value mod k is 9, whichever is bigger. Don't forget that we can also
// include one multiple of k itself (since we only require that the SUM of any two numbers isn't 
// divisible by k).

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> nEleRemainders (k, 0);
    int remainders = 0;
    
    for (int i = 0; i < s.size(); i++){
        remainders = s[i]%k;
        nEleRemainders[remainders]++;
    }
    // 1st scenario
    if (nEleRemainders[0] > 1) nEleRemainders[0] = 1;
    // 2nd scenario
    if (k%2 == 0 && nEleRemainders[k/2] > 1) nEleRemainders[k/2] = 1;
    // 3rd scenario
    for (int i = 1; i < k; i++){
        if (nEleRemainders[i] > nEleRemainders[k-i]) nEleRemainders[k-i] = 0;
        else if (k%2 != 0) { nEleRemainders[i] = 0; }
    }
    
    int result = 0;
    for (int i = 0; i<nEleRemainders.size(); i++){
        result += nEleRemainders[i];
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
