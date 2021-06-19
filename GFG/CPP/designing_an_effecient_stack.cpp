// C++ program that implements stack which has a getMin()
// which is of O(1) time and O(1) space time
#include <bits/stdc++>

using namespace std;

class Mystack
{
	stack<int> s;
	int minEle;		// holds minimum element in the stack

	// Insert an element in the stack
	void __push(int x)
	{
		// If the stack is emepty
		if(s.empty()){
			minEle = x;
			push(x);
			return;
		}
		// If the new element to be inserted is smaller
		// than the minEle;
		if(x < minEle){
			s.push(2*x - minEle);
			minEle = x;
		}
		// if not, just push the number in the stack
		else{
			s.push(x);
		}
	}
	// Remove the topmost element and update the minEle if required
	int __pop()
	{
		if(s.empty())
			return -1;
		int y = s.top();
		s.pop();

		// Minimum element will change, as the min ele is being removed
		if(y < minEle){
			int __val = minEle;  // Store the minEle as this is the actual poped value
			minEle = 2*minEle - y;
			return __val;		// Return the last minEle;
		}
		else
			return y;
	}

	int __peek()
	{
		if(s.empty())
			return -1;

		int t = s.top()
		// If minEle > t, hence minEle stores the value of t
		(t < minEle)? return minEle: return t;
	}
	// Returns the minimum value from the stack in O(1) time and O(1) space
	int getMin()
	{
		if(s.empty())
			return -1;
		else
			return minEle;
	}
};


// Driver Code
int main()
{
	MyStack s;
	s.__push(3);
	s.__push(5);
	s.getMin();
	s.__push(2);
	s.__push(1);
	s.getMin();
	s.__pop();
	s.getMin();
	s.__pop();
	s.__peek();

	return 0;
}
