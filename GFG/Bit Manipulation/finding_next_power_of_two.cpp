#include <iostream>
#include <cmath>
using namespace std;
 
// Compute power of two greater than or equal to `n`
unsigned findNextPowerOf2(unsigned n)
{
    // decrement `n` (to handle the case when `n` itself
    // is a power of 2)
    n = n - 1;
    // initialize result by 2
    int k = 2;
    // double `k` and divide `n` in half till it becomes 0
    while (n >>= 1) {
        k = k << 1;    // double `k`
    }
    return k;
}

int main()
{
    unsigned n = 181;
    cout << "The next power of 2 is " << findNextPowerOf2(n);
    return 0;
}