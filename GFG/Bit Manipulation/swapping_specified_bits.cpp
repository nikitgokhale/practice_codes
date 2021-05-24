#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

/*
    XOR with 1 will toggle the bits
    0 ^ 1 = 1
    1 ^ 1 = 0
     
    XOR with 0 will have no impact
    0 ^ 0 = 0
    1 ^ 0 = 1
*/
// Compute power of two greater than or equal to `n`
int swap(int n, int p, int q)
{
	// If the bits are different at position 'p' and 'q'
    // i.e., neither of them are similar, then only exchange
    if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> p)){
    	n ^= (1 << p);
        n ^= (1 << q);
    }
    return n;
}

int main()
{
    unsigned n = 31;
    int p = 2, q = 6;
    
    cout << n << " in binary is " << bitset<8>(n) << endl;
    n = swap(n, p, q);
    cout << n << " after swapping is " << bitset<8>(n) << endl;
    
    return 0;
}