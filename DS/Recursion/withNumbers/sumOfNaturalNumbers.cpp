#include <bits/stdc++.h>

using namespace std;

int recursiveSum(int input)
{
    // Base Case
    if (input <= 1)
        return input;
    // Shrinking the problem
    return input + recursiveSum(input - 1);
}

int main()
{
    int input;
    cout << "Enter a number: ";
    cin >> input;

    cout << "Sum of natural number till " << input << " is : " << recursiveSum(input);

    return 0;
}
