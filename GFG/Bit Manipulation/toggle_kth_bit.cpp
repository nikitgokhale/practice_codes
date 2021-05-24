#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int toggleKthBit(int n, int k) {
    return n ^ (1 << (k - 1));
}
 
int main()
{
    int n = 20;
    int k = 4;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    n = toggleKthBit(n , k);
    
    cout << n << " after toggling in binary is " << bitset<8>(n) << endl;
 
    return 0;
}