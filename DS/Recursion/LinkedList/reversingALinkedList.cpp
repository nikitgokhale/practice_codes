#include<bits/stdc++.h>

using namespace std;

struct LNode
{
    int data;
    struct LNode* next;
    LNode(int d) {
        data = d;
        next = NULL;
    }
};

// Display the complete list
void display(struct LNode* head)
{
    if (head == NULL)
        return;

    struct LNode* curr = head;
    cout << "The List is: ";
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "|||";
    cout << endl;
}

// Function to create a Linked List
LNode* create(struct LNode* head)
{
    int dataList[8] = {4, 5, 1, 2, 3, 21, 10, 13};
    head = new LNode(dataList[0]);
    LNode* curr = head;
    for (int i = 1;  i < 8; i++) {
        LNode* tmp = new LNode(dataList[i]);
        curr->next = tmp;
        curr = curr->next;
    }
    return head;
}

LNode* reverseList(struct LNode* head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
        return head;

    // Reverse the list and put the first element at last
    LNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    // Return the new head of the reversed list
    return newHead;
}

int main()
{
    struct LNode* head = NULL;
    head = create(head);
    display(head);

    struct LNode* newHead = reverseList(head);
    display(newHead);

    return 0;
}
