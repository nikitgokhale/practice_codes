/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* res = NULL;
        Node* tmp, *prev = NULL;
        int carry = 0, sum;
        
        while(first != NULL || second != NULL){
            sum = carry + (fisrt ? first->data : 0)
                        + (second ? second->data : 0);
            // Update the carry if the sum is greater than 10
            carry = (sum >= 10) ? 1 : 0;
            // Update the sum
            sum = sum % 10;
            // Add this sum to a new node
            tmp = new Node(sum);
            // If this is the fisrt node
            // then set this as the head node
            if(res == NULL)
                res = tmp;
            else
                prev->next = tmp;
            // Set the prev for next insertion
            prev = tmp;
            // Move the list forward
            fisrt = first->next;
            second = second->next;
        }
        // After addition if still carry is remaining
        // Add this to a new node and converge it into the list
        if(carry > 0){
            tmp->next = new Node(carry)
        }
        return res;
    }
};