#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int postionOfTheOnlySetBit(int n) {
	int pos = 0;
    if (n & (n - 1)){
    	cout << "Wrong Input" << endl;
        return 1;
    }
    
    while (n){
    	n = n >> 1;
        pos++;
    }
    return pos;
}
 
int main()
{
    int n = 16;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "The position of the only set bit of " << n << " is " << postionOfTheOnlySetBit(n) << endl;
    return 0;
}