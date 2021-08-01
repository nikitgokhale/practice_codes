#include<bits/stdc++.h>

using namespace std;

long fibo(long n)
{
    if ((n == 0) || (n == 1)) {
        return n;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){
    long input;
    cout << "Enter a number to find Fibonacci number for: ";
    cin >> input;

    cout << "The Fibonacci number for " << input << " is " << fibo(input);

    return 0;
}
