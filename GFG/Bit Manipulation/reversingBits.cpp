#include <iostream>
#include <bitset>
using namespace std;
 
// Function to reverse bits of a given integer
int reverseBits(int n)
{
    int pos = sizeof(int)*8 - 1;     // maintains shift
    // store reversed bits of `n`. Initially, all bits are set to 0
    int reverse = 0;
    // do till all bits are processed
    while (pos >= 0 && n){
        // if the current bit is 1, then set the corresponding bit in the result
        if (n & 1)
            reverse = reverse | (1 << pos);
        n >>= 1;                // drop current bit (divide by 2)
        pos--;                  // decrement shift by 1
    }
    return reverse;
}
 
int main()
{
    int n = 45;
    
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "On reversing, the bits are " << bitset<32>(reverseBits(n)) << endl;
}
