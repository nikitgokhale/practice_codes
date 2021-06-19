/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* curr = head;
        Node* tmp = NULL;
        Node* end = head;
        
        // Traversing to the last node in the linked list
        while (end->next != NULL)
            end = end->next;
            
        // Rotating the list until k == 0
        while(k--){
            tmp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = curr;
            curr = tmp;
        }
        return curr;
    }
};