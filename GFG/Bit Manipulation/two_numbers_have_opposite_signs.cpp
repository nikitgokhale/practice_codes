#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
  int x = 5;
  int y = 9;
  
  cout << x << " in binary is " << bitset<32>(x) << endl;
  cout << y << " in binary is " << bitset<32>(y) << endl;
  
  bool opposite = ((x ^ y) < 0);
  
  if (opposite)
  	cout << x << " and " << y << " have opposite signs" << endl;
  else
  	cout << x << " and " << y << " doesn't have opposite signs" << endl;
  return 0;
}