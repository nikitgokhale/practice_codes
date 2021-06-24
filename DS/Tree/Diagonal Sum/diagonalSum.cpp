/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

/*
    Algorithm: 
The idea is to keep track of vertical distance from top diagonal passing through the root. 
We increment the vertical distance we go down to next diagonal.
	- Add root with vertical distance as 0 to the map.
	- For processing/moving to the right child, keep the vertical distance as it is
	- For processing/moving to the right child, increment the vertical distance by 1
Repeat this steps recursively to return the map to the wrapper function;
Iterate through the map, and add the sum of every vd to a vector;
Return the vector

*/
void diagonalSumUtil(Node* root, int vd, map <int, int>& diagonalSum)
{
    if (!root)
        return;
        
    diagonalSum[vd] += root->data;
    // Increase the vertical distance if left child
    diagonalSumUtil(root->left, vd+1, diagonalSum);
    // Vertical Distance of right child remain same
    diagonalSumUtil(root->right, vd, diagonalSum);
}

vector <int> diagonalSum(Node* root) {
    // Add your code here
    vector<int> res;    
    map <int, int> diagonalSum;
    diagonalSumUtil(root, 0, diagonalSum);
    
    map<int, int>::iterator it;
    for (it = diagonalSum.begin(); it!=diagonalSum.end(); it++){
        res.push_back(it->second);
    }
    return res;
}