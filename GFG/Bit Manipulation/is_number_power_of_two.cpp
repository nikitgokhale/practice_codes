#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int powerOfTwo(int n) {
    return n & (n - 1);
}
 
int main()
{
    int n = 20;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    if (!powerOfTwo(n))
    	cout << n << " is power of 2" << endl;
    else
    	cout << n << " is not power of 2" << endl;
 
    return 0;
}