#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int swap(int n, int p, int q, int b)
{
	// take XOR of bits to be swapped
    int x = ((n >> p) ^ (n >> q));
    // only consider the last b–bits of `x`
    x = x & ((1 << b) - 1);
    // replace the bits to be swapped with the XORed bits
    // and take its XOR with `n`
    return n ^ ((x << p) | (x << q));
}

int main()
{
    int n = 15;   		// Input
    int p = 2, q = 5;   // position of the bits to be swapped
    int b = 2; 			// Number of consecutive bits to be swapped
    
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << n << " after swapping is " << bitset<8>(swap(n, p, q, b)) << endl;
    
    return 0;
}