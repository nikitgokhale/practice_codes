#include <iostream>
#include <bitset>
using namespace std;
 
// Function to count the total number of set bits in `n`
bool checkforPower4(int n)
{
	// return true if `n` is a power of 2, and its only
    // set bit is present at even position
    return n && !(n & (n-1)) && !(n & 0xAAAAAAAA);
}
 
int main()
{
    int n = 64;
 
    if (checkforPower4(n))
    	cout << n << " is a power of 4" << endl;
    else
    	cout << n << " is not a power of 4" << endl;
    return 0;
}