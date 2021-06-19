/* This approach uses Level Order Traversal
   We use level order traversal, because in the question, it is mentioned that 
   "If there are multiple nodes passing through a vertical line, 
   then they should be printed as they appear in level order traversal of the tree."
   So to print the nodes present in the vertical line same as they appear, we use Level Order Traversal 

Approach:
    1. To maintain a hash for the branch of each node.
    2. Traverse the tree in level order fashion.
    3. In level order traversal, maintain a queue
       which holds, node and its vertical branch.
        * pop from queue.
        * add this node's data in vector corresponding
          to its branch in the hash.
        * if this node hash left child, insert in the 
          queue, left with branch - 1.
        * if this node hash right child, insert in the 
          queue, right with branch + 1.

*/

class
{
    public:
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> res;
        map<int, vector<int>> mp;
        int hd = 0;
        
        // Create queue to do level order traversal.
        // Every item of queue contains node and
        // horizontal distance.
        queue<pair<Node* , int>> q;
        q.push(make_pair(root, hd));
        
        while(!q.empty()){
            pair<Node* , int> tmp = q.front();
            q.pop();
            hd = tmp.second;
            Node* curr = tmp.first;
            
            // Insert the node's data in the map
            mp[hd].push_back(curr->data);
            
            if(curr->left)
                q.push(make_pair(curr->left, hd-1));
            if(curr->right)
                q.push(make_pair(curr->right, hd+1));
        }
        
        // Traversing the map and adding the node's data
        // in vector at every horizontal distance hd
        map<int, vector<int>> :: iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            for(int i = 0; i < it->second.size(); i++){
                res.push_back(it->second[i]);
            }
        }
        return res;
    }
};
