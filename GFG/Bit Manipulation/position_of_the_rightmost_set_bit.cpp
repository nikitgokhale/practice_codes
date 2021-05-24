#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int postionOfRightmostSetBit(int n) {
	int pos = 0;
	// If the number is Odd
    if (n & 1)
    	return 1;
        
    n = n ^ (n & (n-1));
    
    while (n){
    	n = n >> 1;
        pos++;
    }
    return pos;
}
 
int main()
{
    int n = 20;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "The position of the rightmost set bit of " << n << " is " << postionOfRightmostSetBit(n) << endl;
    return 0;
}