#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
	int x = 65;
    int y = 80;
    
    cout << x << " in binary is " << bitset<8>(x) << endl;
    cout << y << " in binary is " << bitset<8>(y) << endl;
    int n = x ^ y;
    
    int count = 0;
    // Normal calculation of set bits
    while (n) {
    	n = n & (n-1);
        count++;
    }
    
    cout << count << " bits needs to be flipped!" << endl;
	return 0;
}