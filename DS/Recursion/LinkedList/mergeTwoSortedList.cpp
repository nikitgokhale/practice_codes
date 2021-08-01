#include <bits/stdc++.h>

using namespace std;

struct LNode
{
    int data;
    LNode* next;
    LNode(int d){
        data = d;
        next = NULL;
    }
};

// Display Function'
void display(LNode* head)
{
    if (head == NULL)
        return;
    LNode* curr = head;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "||";
    cout << endl;
}

// Create a List Function
LNode* createList(LNode* head, vector<int> dataList)
{
    head = new LNode(dataList[0]);
    int n = dataList.size();
    cout << n << endl;
    LNode* curr = head;
    for (int i = 1; i < n; i++) {
        LNode* tmp = new LNode(dataList[i]);
        curr->next = tmp;
        curr = curr->next;
    }
    return head;
}

LNode* mergeSortedList(LNode* head1, LNode* head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data < head2->data) {
        head1->next = mergeSortedList(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeSortedList(head1, head2->next);
        return head2;
    }
}

int main()
{
    vector<int> dataList1 = {1, 7, 15, 23, 25, 36, 38, 40};
    vector<int> dataList2 = {2, 4, 8, 16, 32, 64, 128, 256};

    LNode* head1 = NULL;
    LNode* head2 = NULL;
    head1 = createList(head1, dataList1);
    head2 = createList(head2, dataList2);
    cout << "Before Merging: " << endl;
    display(head1);
    display(head2);

    cout << "After merging: " << endl;
    LNode* newHead = mergeSortedList(head1, head2);
    display(newHead);

    return 0;
}
