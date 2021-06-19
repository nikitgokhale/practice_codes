/* Tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    /*
        Approach 1:
        This approach uses recursive technique to get the sum of the nodes in the right
        subtree and the left subtree
        Check if the sum calculated is equal to root's data
        Also check if the left subtree and the right subtree are
        sum tree or not
        O(n^2) time complexity
     */

    int findSum(Node* node)
    {
        if(node == NULL)
            return 0;
        return (node->data + findSum(node->left) + findSum(node->right));
    }
    
    bool isSumTree(Node* root)
    {
        // Your code here
        if(root == NULL || (node->left == NULL) && (node->right == NULL))
            return 1;
        int rootData = root->data;
        // Get the sum of the nodes in the left and right subtree
        int leftData = findSum(root->left);
        int rightData = findSum(root->right);
        
        int sum = leftData + rightData;
        
        if(rootData == sum 
           && (isSumTree(root->left)) 
           && (isSumTree(root->right)))
            return true;
        else
            return false;
    }

    /*
        Approach2: 
        This approach uses the following rules to get the sum directly. 
        1) If the node is a leaf node then the sum of the subtree rooted 
           with this node is equal to the value of this node. 
        2) If the node is not a leaf node then the sum of the subtree rooted 
           with this node is twice the value of this node 
        (Assuming that the tree rooted with this node is SumTree).
        O(1) time complexity
     */
    bool isLeaf(Node* node)
    {
        if(node == NULL)
            return false;
        if(node->left == NULL && node->right == NULL)
            return true;
        return false;
    }

    bool __isSumTree(Node* root)
    {
        int leftSum = 0, rightSum = 0;
        if(root == NULL || isLeaf(root))
            return 1;

        if(__isSumTree(root->left) && __isSumTree(root->right)){
            // Get the sum of the nodes in the left subtree
            if(root->left == NULL)
                leftSum = 0;
            else if (isLeaf(node->left))
                leftSum = root->left->data;
            else
                leftSum = 2 * (root->left->data);

            // Get the sum of the nodes in the right subtree
            if(root->right == NULL)
                rightSum = 0;
            else if(isLeaf(root->right))
                rightSum = root->right->data;
            else
                rightSum = 2 * (root->right->data);

            return (root->data == leftSum + rightSum);
        }
        return 0;
    }
};