#include <iostream>
#include <bitset>
using namespace std;
 
// Function to count the total number of set bits in `n`
bool checkforPower8(int n)
{
	// return true if `n` is a power of 2, and its only
    // set bit is present at (0, 3, 6, … ) position
    return n && !(n & (n-1)) && !(n & 0xB6DB6DB6);
}
 
int main()
{
    int n = 516;
 
    if (checkforPower8(n))
    	cout << n << " is a power of 8" << endl;
    else
    	cout << n << " is not a power of 8" << endl;
    return 0;
}
