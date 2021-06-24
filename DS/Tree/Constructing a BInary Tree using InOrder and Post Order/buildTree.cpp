/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int search(int in[], int iStart, int iEnd, int data)
{
    int i;
    for (i = iStart; i <= iEnd; i++){
        if (in[i] == data)
            break;
    }
    return i;
}

Node* buildTreeUtil(int in[], int post[], int iStart, int iEnd, int* pIndex)
{
    if (iStart > iEnd)
        return NULL;
    
    Node* tmp = new Node(post[*pIndex]);
    (*pIndex)--;
    
    if (iStart == iEnd)
        return tmp;
        
    int ix = search(in, iStart, iEnd, tmp->data);
    
    tmp->right = buildTreeUtil(in, post, ix+1, iEnd, pIndex);
    tmp->left = buildTreeUtil(in, post, iStart, ix-1, pIndex);
    
    return tmp;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int pIndex = n-1;
    return buildTreeUtil(in, post, 0, n-1, &pIndex);
}