#include<stdc++.h>
#include<stack>

/* The simple logic behind creating a Queue using two stacks is the for Queue the elements are inserted/removed in FIFO manner
 * and in Stacks, the elements are pushed/poped in LIFO manner.
 * So to make a stack look like queue, we have to take two stacks.
 * For pop operation, we have to take all the elements from one stack and transfer is into the another stacksby poping from 1 and pushing in one.
 * With which we can get the
 */

using namespace std;

class StackQueue {
private:
	/* These are STL stacks ( http://goo.gl/LxlRZQ ) */
	stack<int> s1;
	stack<int> s2;
public:
	void push(int B);
	int pop();
};

/* This method is to push the element into the stack1 */
void StackQueue::push(int x)
{
	/* Just a simple push required */
	s1.push(x);
}

int StackQueue::pop()
{
	/* If S2 is empty, transfer all the elements of S1 to S2 and pop out the first element */
	if (s2.empty()) {
		if (s1.empty()){
			return -1;
		}
		else {
			while (!s1.empty()) {
				int ele = s1.top();   // Get the element at the topmost position in the Stack, which will be the 1st element in the Queue
				s1.pop();
				s2.push(ele);
			}
			int ele = s2.top();
			s2.pop();
			return ele;
		}
	}
	else {
		int ele = s2.top();
		s2.pop();
		return ele;
	}
}

int main()
{
	int N;
	cout << "Enter the number of elements: ";
	cin >> N;

	StackQueue* sq = new StackQueue();

	while (N--) {
		int QueryType = 0;
		cout << "Enter the query type: either 1(push) or 2(pop): ";
		cin >> QueryType;
		if (QueryType == 1) {
			int item;
			cout << "Enter the data to be Pushed in the Queue: ";
			cin >> item;
			sq->push(item);
		}
		else if (QueryType == 2) {
			cout << sq->pop() << endl;
		}
		else{
			cout << "Invalid Query Type selected!" << endl;
			return -1;
		}
		cout << endl;
	}
}