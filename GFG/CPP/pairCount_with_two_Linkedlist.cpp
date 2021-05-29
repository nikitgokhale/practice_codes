/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        int pairCount = 0;
        unordered_set<int> s1;
        Node* curr1 = head1;
        Node* curr2 = head2;
        // Add the data from the 1st linked list into a set
        while (curr1 != NULL){
            s1.insert(curr1->data);
            curr1 = curr1->next;
        }
        
        // Look for (sum - list2[i) in the set. by traversing through
        // the set; if found increment the pair count
        while (curr2 != NULL){
            if (s1.find(x-curr2->data) != s1.end())
                pairCount++;
            curr2 = curr2->next;
        }
        return pairCount;
    }
}