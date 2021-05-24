#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void swap(int& x, int& y)
{
	if (x != y){
    	x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}

int main() {
	int x = 4;
    int y = 10;
    
    cout << "Before swapping " << x << " and " << y << endl;
    swap(x, y);
    cout << "After swapping " << x << " and " << y << endl;
 
    return 0;
}
