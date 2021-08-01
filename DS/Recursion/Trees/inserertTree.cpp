#include <bits/stdc++.h>

using namespace std;

struct TNode
{
    int data;
    TNode* left;
    TNode* right;
    TNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TNode* insert(TNode* head, int data)
{
    if (head == NULL) {
        head = new TNode(data);
        return head;
    }

    if (head->data < data) {
        head->right = insert(head->right, data);
    }
    else {
        head->left = insert(head->left, data);
    }
    return head;
}

void PreOrder(TNode* root)
{
    if (root) {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void printLeaves(TNode* root)
{
    if (root == NULL)
        return;

    if (root->left == NULL &&
    root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    if (root->left != NULL)
        printLeaves(root->left);

    if (root->right != NULL)
        printLeaves(root->right);
}

int main()
{
    TNode* root = NULL;
    vector<int> dataList = {23, 12, 15, 5, 7, 31, 29, 88, 53};

    for (auto itr: dataList) {
        root = insert(root, itr);
    }

    cout << "The PreOrder is: ";
    PreOrder(root);
    cout << endl;

    cout << "Leaves in the tree are: ";
    printLeaves(root);

    return 0;
}
