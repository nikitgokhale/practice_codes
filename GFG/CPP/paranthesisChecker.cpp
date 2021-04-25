#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool ispar(string x)
{
    // Your code here
    stack<char> s;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[') {
            s.push(x[i]);
        }
        else {
            if (s.empty())
                return false;

            char c = s.top();
            if (x[i] == ')' && c != '(')
                return false;
            else if (x[i] == '}' && c != '{')
                return false;
            else if (x[i] == ']' && c != '[')
                return false;
            s.pop();
        }
    }
    return s.empty();
}


int main()
{
    string a;
    cout << "Enter a parenthesis string: ";
    cin >> a;

    if (ispar(a)) {
        cout << "IsBalanced" << endl;
    }
    else {
        cout << "NotBalanced" << endl;
    }

	cout << "Hello World" << endl;
	return 0;
}