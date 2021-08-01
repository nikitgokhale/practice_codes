#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string inputStr, size_t start, size_t end) {
    // Base Condition - Stopping condition
    if (start >= end){
        return true;
    }
    // Shrinking the problem
    else {
        // will return "False" if condition not satisfied
        return ((inputStr[start] == inputStr[end]) && isPalindrome(inputStr, start+1, end-1));
    }
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int length = input.length();

    cout << "Is input string palindrome ";
    if (isPalindrome(input, 0, length-1)) {
        cout << "True";
    }
    else {
        cout << "False.";
    }

    return 0;
}
