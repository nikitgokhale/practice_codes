#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
unsigned findParity(unsigned n) {
	bool parity = false;
    
    while (n) {
    	parity = !parity;
        
        n = n & (n-1);
    }
    return parity;
}
 
int main()
{
    unsigned n = 31;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    if (findParity(n))
    	cout << "The parity of " << n << " is Odd" << endl;
    else
    	cout << "The parity of " << n << " is Even" << endl;
    return 0;
}