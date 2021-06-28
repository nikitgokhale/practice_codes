#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

/*
    Approach:
    As we want to spend all the money during each trip, i.e., if we have 5 dollors
    we have to spend it completely in each trip, we know that Ci + Cj = M, where \
    Ci and Cj are the costs of each flavor which eqauls to the total money M.
    If we have Ci, then Cj = M - Ci; we just have to find if this is present in
    the cost_array, and if yes return the indices of Ci and Cj.
    1. Loop over the cost array
    2. Keep storing the indices of every distinct ice cream in the map with key as
       the ice cream's cost and value as its index
       - If in the map, there exist "money - cost[i]", then we print the index of
         the ice cream stored in the map and the current index.
    Keep iterating till the end of the array.
    ** As this uses a Binary Search algorithm to find the pair which eqauls the 
    total given money, the time complexity can be of O(log n), but we'll have to
    iterate through the whole array to find all the other pairs as well
    The time complexity is O(nlogn)
*/

void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    int ans1 = -1, ans2 = -1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        ans2 = i;
        if (mp.count(money - cost[i])) {
            ans1 = mp[money - cost[i]];
            cout << ans1 + 1 << " " << ans2 + 1 << endl;;
            return;
        }
        mp[cost[i]] = i;
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
