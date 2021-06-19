// C++ program that implements two stack using one array
#include <bits/stdc++>

using namespace std;

class twoStacks
{
	int arr*;
	int size;
	int top1, top2;
public:
	twoStack(int n)
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = n;
	}

	// Method to push an element in the stack1
	void __push1(int x)
	{
		// If there is atleast one empty space left for stack1
		if (top1 < top2-1){
			top1++;
			arr[top1] = x
		}
		else{
			cout << "Stack1 Overflow!" << endl;
			exit(1);
		}
	}
	// Method to push an element in the stack2
	void __push2(int x)
	{
		// If there is atleast one empty space left for stack2
		if (top2 > top1+1){
			top2--;
			arr[top2] = x;
		}
		else{
			cout << "Stack2 Overflow!" << endl;
			exit(1);
		}
	}
	// Method to pop an element from the stack1
	int __pop1()
	{
		if(top < 0){
			cout << "Stack1 Underflow!" << endl;
			exit(1);
		}
		int t = arr[top1];
		top1--;
		return t;
	}
	// Method to pop and element from the stack1
	int __pop2()
	{
		if (top2 > size-1){
			cout << "Stack2 Underflow!" << endl;
			exit(1);
		}
		int t = arr[top2];
		top2++;
		return t;
	}

}

int main()
{

	return 0;
}