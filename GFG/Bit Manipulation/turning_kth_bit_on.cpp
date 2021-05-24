#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int turnOnKthBit(int n, int k) {
    return n | (1 << (k - 1));
}
 
int main()
{
    int n = 15;
    int k = 6;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "Turning " << k << "'th bit ON\n";
    n = turnOnKthBit(n, k);
    cout << n << " in binary is " << bitset<8>(n) << endl;
 
    return 0;
}