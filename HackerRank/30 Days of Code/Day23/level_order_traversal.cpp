#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

	void levelOrder(Node * root){
        //Write your code here
        queue<Node*> que;
        vector<int> vt;
        que.push(root);
        while (!que.empty()){
            Node *tmp = que.front();
            vt.push_back(tmp->data);
            que.pop();
            if (tmp->left){
                que.push(tmp->left);
            }
            if (tmp->right){
                que.push(tmp->right);
            }
        }
        for (int i = 0; i < vt.size(); i++){
            cout << vt[i] << " ";
        }
	}

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}