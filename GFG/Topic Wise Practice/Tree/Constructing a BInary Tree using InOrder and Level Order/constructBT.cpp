Node* buildTreeUtil(int inorder[], int levelOrder[], int iStart, int iEnd, int i, int n)
{
    //add code here.
    if (i >= n)
        return NULL;
    // Creating root node from the levelOder Array    
    Node* tmp = new Node(levelOrder[i]);
    int j = iStart;
    // Splitting the Left SubTree from root and right subtree from root
    while (inorder[i] != tmp->key && j <= iEnd){
        j++;
    }
    tmp->left = buildTreeUtil(inorder, levelOrder, iStart, j, 2*i+1, n);
    tmp->right = buildTreeUtil(inorder, levelOrder, i+1, iEnd, 2*i+2, n);
    
    return tmp;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    return buildTreeUtil(inorder, levelOrder, iStart, iEnd, 0, n);
}