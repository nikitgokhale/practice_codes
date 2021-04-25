#include<stdc++.h>

using namespace std;


vector<long long> nextLargerElement(vector<long long> arr, int n) {
    // Your code here
    stack<long long> stack_arr;
    vector<long long> vect_arr;
    stack_arr.push(arr[n - 1]);
    vect_arr.push_back(-1);
    for (int i = n-2; i >= 0; i--) {
        while (!stack_arr.empty() && stack_arr.top() <= arr[i])
            stack_arr.pop();
        long long ng = (stack_arr.empty() ? -1 : stack_arr.top());
        vect_arr.push_back(ng);
        stack_arr.push(arr[i]);
    }
    reverse(vect_arr.begin(), vect_arr.end());
    return vect_arr;
}

int main()
{
    int size;
    cout << "Enter the the size of the vector: ";
    cin >> size;
    vector<long long> arr(size);
    cout << "Enter the elements in the vector: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<long long> ret = nextLargerElement(arr, size);
    for (long long i : ret)
        cout << i << " ";
    cout << endl;
    return 0;
}