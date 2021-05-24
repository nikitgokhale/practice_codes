#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

// Naive iterative solution to calculate `pow(x, n)`
int powerNaive(int x, unsigned n)
{
    // initialize result by 1
    int pow = 1;
    // multiply `x` exactly `n` times
    for (int i = 0; i < n; i++) {
        pow = pow * x;
    }
    return pow;
}

// Naive recursive solution to calculate `pow(x, n)`
// using divide-and-conquer
int powerNaiveRecur(int x, unsigned n)
{
	if (n == 0)
    	return 1;
        
    if (n & 1){
		return x * powerNaiveRecur(x, n/2) * powerNaiveRecur(x, n/2);
    }
    
    return powerNaiveRecur(x, n/2) * powerNaiveRecur(x, n/2);
}

// Optimized recursive solution to calculate `pow(x, n)`
// using divide-and-conquer
int powerOptRecur(int x, unsigned n)
{
	if (n == 0)
    	return 1;
    int pow = powerOptRecur(x, n/2);
    
    if (n & 1){
    	return x * pow * pow;
    }
    
    return pow * pow;
}

// Iterative function to calculate `pow(x, n)` using
// binary operators
// O(log(n)) solution
int power(int x, unsigned n)
{
    // initialize result by 1
    int pow = 1;
    // loop till `n` become 0
    while(n){
      // if `n` is odd, multiply the result by `x`
      if (n & 1)
        pow *= x;
      // divide `n` by 2
      n = n >> 1;
      // multiply `x` by itself
      x = x * x;
    }
    return pow;
}
 
int main(void)
{
    int x = -2;
    unsigned n = 3;
    printf("powerNaive(%d, %d) = %d\n", x, n, powerNaive(x, n));
    printf("powerNaiveRecur(%d, %d) = %d\n", x, n, powerNaiveRecur(x, n));
    printf("powerOptRecur(%d, %d) = %d\n", x, n, powerOptRecur(x, n));
    printf("power(%d, %d) = %d\n", x, n, power(x, n));
 
    return 0;
}