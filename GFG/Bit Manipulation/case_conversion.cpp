#include <iostream>
#include <bitset>
using namespace std;
 
/* ‘A’ — 01000001 ‘a’ — 01100001
‘B’ — 01000010 ‘b’ — 01100010
‘C’ — 01000011 ‘c’ — 01100011
‘D’ — 01000100 ‘d’ — 01100100
‘E’ — 01000101 ‘e’ — 01100101
and so on… */
/* Only the 3 significant bit has to be toggled, which can be done
   by XORing the character with ' ' - whose binary for is
   ' ' - 00100000 */
 
int main()
{
    // Coverting Uppercase to Lowercase
    for (char ch = 'A'; ch <= 'Z'; ch++)
    	cout << char(ch | ' ');
        
    cout << endl;
        
    // Converting Lowercase to Uppercase
    for (char ch = 'a'; ch <= 'z'; ch++)
    	cout << char(ch & '_');
        
    // The All-in-One case
    cout << endl;
    // Coverting Uppercase to Lowercase
    for (char ch = 'A'; ch <= 'Z'; ch++)
    	cout << char(ch ^ ' ');
        
    cout << endl;
        
    // Converting Lowercase to Uppercase
    for (char ch = 'a'; ch <= 'z'; ch++)
    	cout << char(ch ^ ' ');
}