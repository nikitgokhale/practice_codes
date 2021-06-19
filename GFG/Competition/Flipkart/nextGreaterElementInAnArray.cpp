class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        /*
         Approach: Using Stack, pushing in reverse order
         We will use stack to find the next greater element of the given element
         1. Declare one resultant vector and stack.
            Push the last element (n-1) in the stack and push -1 in the vector (as the condition says
            the last element next greater element is -1);/
         2. Use a for loop to traverse the array in reverse order from n-2 to 0
            - inside the for loop keep a condition to pop from the stack when:
              The stack is not empty and the top element is smaller or equal to the current
              elememt
            - Get the top element from the stack and push it into the vector
            - push the current element in the stack
         3. Reverse the stack and return 

         */
        
        vector<long long> res;
        stack<long long> st;
        st.push(arr[n-1]);
        res.push_back(-1);
        
        for (int i = n-2; i >= 0; i--) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            long long greater = (st.empty()? -1: st.top());
            res.push_back(greater);
            st.push(arr[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};