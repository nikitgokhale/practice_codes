/*
struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* curr = head;
        Node* next = NULL, *res = NULL;  // Resultant header and a reference node
        // Run the loop until curr != NULL;
        while (curr != NULL){
            next = curr->next;
            curr->next = res;
            res = curr;
            curr = next;
        }
        return res;
    }
    
};
  