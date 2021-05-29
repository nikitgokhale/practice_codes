#include <iostream>
#include <bitset>
using namespace std;

// This is Brian Kernighan's rule
// Where in every iteration we turn off the rightmost set bit of the number
// Making the iterations less and the code more effecient.
// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
 
int main()
{
    int n = 55;
 
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "The total number of set bits in " << n << " is "
         << countSetBits(n) << endl;
    return 0;
}
