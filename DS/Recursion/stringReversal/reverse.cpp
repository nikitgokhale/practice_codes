#include <bits/stdc++.h>

using namespace std;

void reverse(string inputStr)
{
    // Base Case
    if (inputStr.size() == 0) {
        return;
    }
    // Shrinking the problem letter by letter and printing out the
    // letter at 0th index of the substring
    reverse(inputStr.substr(1));
    cout << inputStr[0];
}

int main()
{
    string input;
    cout << "Enter string to reverse: ";
    cin >> input;

    reverse(input);

    return 1;
}
