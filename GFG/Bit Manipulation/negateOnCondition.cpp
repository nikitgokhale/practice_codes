#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

// Negate only when `flag` is true
int negateWhenFlagTrue(int n, bool flag) {
    return (n ^ -flag) + flag;
}

int negateWhenFlagFalse(int n, bool flag)
{
	return (flag ^ (flag-1)) * n;
}
 
int main()
{
    int n = 2;
 
    std::cout << "Don't Negate " << negateWhenFlagTrue(n, 0) << std::endl;
    std::cout << "Negate " << negateWhenFlagTrue(n, 1) << std::endl;

    std::cout << "Don't Negate " << negateWhenFlagFalse(n, 1) << std::endl;
    std::cout << "Negate " << negateWhenFlagFalse(n, 0) << std::endl;
 
    return 0;
}