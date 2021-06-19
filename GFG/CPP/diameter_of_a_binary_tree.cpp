
struct Node
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
        // Computing the left height from the given node    
        int leftH = height(root->left);
        // Computing the right height from the given node
        int rightH = height(root->right);
        // Computing the left diamenter from the given node
        int leftDiameter = diameter(root->left);
        // Computing the right diameter from the given node
        int rightDiameter = diameter(root->right);
        // Returning the max between the height and the diameter
        return max(leftH+rightH+1, max(leftDiameter, rightDiameter));
    }

};