#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int checkForKthBit(int n, int k) {
    return n & (1 << (k - 1));
}
 
int main()
{
    int n = 20;
    int k = 3;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "Checking if the " << k << "'th bit is ON\n";
    if (checkForKthBit(n, k))
    	cout << k << "'th bit is set" << endl;
    else
    	cout << k << "'th bit is not set." << endl;
 
    return 0;
}