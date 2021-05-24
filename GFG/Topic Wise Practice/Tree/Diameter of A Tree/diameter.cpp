/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */



class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    int height(Node* root)
    {
        if (!root)
            return 0;
            
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        if (leftH > rightH)
            return leftH+1;
        else
            return rightH+1;
    }
  
    int diameter(Node* root)
    {
        // Your code here
        if (!root)
            return 0;
        // Case A: When the diameter passes through the root.    
        int leftH = height(root->left);
        int rightH = height(root->right);
        // Case B: When the diameter does not pass through the root.
        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);
        //         Passing through     Not Passing through
        //         the root.           the root.
        return max(leftH+rightH+1, max(leftDiameter, rightDiameter));
    }

};