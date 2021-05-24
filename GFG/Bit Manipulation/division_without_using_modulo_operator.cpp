#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

// Function to compute `n % d` without using division and modulo operator
int compute(int n, int d)
{
	while (n > 0)
    	n = n - d;
    return n+d;
}
 
int main(void)
{
    const unsigned int n = 18;
    const unsigned int d = 8;
    
    unsigned int p = compute(n, d);
    printf("%d %% %d = %d\n", n, d, p);
 
    return 0;
}