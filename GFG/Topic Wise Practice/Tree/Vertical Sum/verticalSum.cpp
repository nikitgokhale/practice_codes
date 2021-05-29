/*struct Node{
int data;
Node *left,*right;
};
*/
/*
Algorithm: 
The idea is to keep track of level. When move left , decrement level by 1. 
When move right, increment level by 1. Store node's sum in respective level 
    - Add root with level as 0  to the map;
    - For processing/moving to the left child, decrement the level by one
    - For processing/moving to the right child, increment the level by one.
Repeat these steps recursively and return the map to the wrapper function.
Iterate through the map, and add the sum of every level to a vector;
Return the vector
*/

class Solution{
  public:
    void verticalSumUtil(Node* root, int lvl, map<int, int>& levelMap)
    {
        if (!root)
            return;
        levelMap[lvl] += root->data;
        // when moving left, decrement level by 1
        verticalSumUtil(root->left, lvl-1, levelMap);
        // When moving right, increment level by 1
        verticalSumUtil(root->right, lvl+1, levelMap);
    }
  
    vector <int> verticalSum(Node *root) {
        // add code here.
        vector<int> res;
        map<int, int> levelMap;
        
        verticalSumUtil(root, 0, levelMap);
        
        map<int, int>::iterator it;
        for (it = levelMap.begin(); it != levelMap.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }