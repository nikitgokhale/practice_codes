/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node * mergeResult(Node *p1, Node *p2)
{
    // your code goes here
    if ((p1 == NULL) && (p2 == NULL))
        return NULL;
    
    Node* res = NULL;
    while ((p1 != NULL) && (p2 != NULL)){
        if (p1->data <= p2->data){
            Node* tmp = p1->next;
            p1->next = res;
            res = p1;
            p1 = tmp;
        }
        else{
            Node* tmp = p2->next;
            p2->next = res;
            res = p2;
            p2 = tmp;
        }
    }
    while (p1 != NULL){
        Node* tmp = p1->next;
        p1->next = res;
        res = p1;
        p1 = tmp;
    }
    while (p2 != NULL){
        Node* tmp = p2->next;
        p2->next = res;
        res = p2;
        p2 = tmp;
    }
    return res;
}