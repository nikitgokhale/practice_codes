#include <bits/stdc++.h>

using namespace std;

void findBinary(int dec)
{
    if (dec == 0)
        return;

    findBinary(dec/2);
    cout << dec%2;
}

int main()
{
    int dec;
    cout << "Enter number to find it's binary equivalent: ";
    cin >> dec;

    findBinary(dec);

    return 0;
}
