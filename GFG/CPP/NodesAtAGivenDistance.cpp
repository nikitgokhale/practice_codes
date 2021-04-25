class Solution
{
private:

public:
    Node* searchNode(Node* root, int tar)
    {
        if (root){
            if (root->data == tar)
                return root;
            searchNode(root->left, tar);
            searchNode(root->right, tar);
        }
        else{
            return NULL;
        }
    }
    
    void fillParent(Node* root, Node* par, unordered_map<Node*, Node*>&parentMap)
    {
        if (root == NULL)
            return;
        parentMap[root] = par;
        fillParent(root->left, root, parentMap);
        fillParent(root->right, root, parentMap);
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        if (root == NULL || k < 0)
            return NULL;
        Node* targetRoot = searchNode(root, tar);
        unordered_map<Node*, Node*>parentMap;
        fillParent(root, NULL, parentMap);
        unordered_map<Node*, int>visMap;
        vector<int> retVal;
        visMap[targetRoot] = 1;
        queue<Node*> q;
        q.push(targetRoot);
        int dist = 0
        while (!q.empty())
        {
            int size = q.size();
            if (dist == k){
                while (size > 0){
                    retVal.push_back(q.front()->data);
                    q.pop();
                    size--;
                }
            }
            while (size > 0){
                Node* ptr = q.front();
                q.pop();
                if (ptr->left && !visMap[ptr->left]){
                    visMap[ptr->left] = 1;
                    q.push(ptr->left);
                }
                if (ptr->right && !visMap[ptr->right]){
                    visMap[ptr->right] = 1;
                    q.push(ptr->right);
                }
                if (parentMap[ptr] && !visMap[parentMap[ptr]]){
                    visMap[parentMap[ptr]] = 1;
                    q.push(parentMap[ptr]);
                }
                size--;
            }
            dist++;
        }
        sort(retVal.begin(), retVal.end());
        return retVal;
    }
};  