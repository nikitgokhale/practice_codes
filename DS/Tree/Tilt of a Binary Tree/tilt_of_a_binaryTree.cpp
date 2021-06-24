/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
void pathCountsHelper(Node* root, int pathLen, map<int, int>& res)
{
    if (root == NULL)
        return;
    
    // Incrementing the no of paths with the current path length    
    if (root->left == NULL && root->right == NULL){
        res[pathLen]++;
        return;
    }
    
    // Recursively call for left and right subtrees with
    // incrementing path lengths.
    pathCountsHelper(root->left, pathLen+1, res);
    pathCountsHelper(root->right, pathLen+1, res);
}

void pathCounts(Node *root)
{
    //Your code here
    map<int, int> res;

    pathCountsHelper(root, 1, res);
    
    for (auto x: res){
        cout << x.first << " " << x.second << " $";
    }
}