/* The above solution uses preorder traversal and Hashmap to store nodes according 
   to horizontal distances. 
   Since the above approach uses preorder traversal, nodes in a vertical line may 
   not be printed in the same order as they appear in the tree.
             1
          /     \
         2       3
        /  \    /  \
       4    5  6    7
                \  /  \
                 8 10  9 
                     \
                     11
                       \
                        12

    For example, the above solution prints 12 before 9 in the below tree.
*/

//Function to find the vertical order traversal of Binary Tree.
// Wrapper function to get the vertical order of 
/// the binary tree in the map
    void getVerticalOrder(Node* root, int hd, multimap<int, int>& mp)
    {
        // Base Case
        if (root == NULL)
            return;
        
        // Store the current node in the map
        mp.insert({hd, root->data});
        //mp[hd].push_back(root->data);
        // For left subtree
        getVerticalOrder(root->left, hd-1, mp);
        // For right subtree
        getVerticalOrder(root->right, hd+1, mp);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        int hd = 0;
        multimap<int, int> mp;
        vector<int> res;
        // Wrapper function to get the vertical order of 
        // the binary tree in the map
        getVerticalOrder(root, hd, mp);
        
        // Iterating through the map and storing the second 
        // value of the map in a vector
        //map<int, int> :: iterator it;
        for (auto it = mp.begin(); it != mp.end(); it++){
            res.push_back(it->second);
            /*for(int i = 0; i < it->second.size(); ++i){
                res.push_back(it->second[i]);
            }*/
        }
        return res;
    }