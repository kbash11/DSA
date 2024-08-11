/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* nodeLeft,Node* nodeRight){
        if(!nodeLeft || !nodeRight){
            return;
        }
        nodeLeft->next=nodeRight;
        solve(nodeLeft->right,nodeRight->left);
        solve(nodeLeft->left,nodeLeft->right);
        solve(nodeRight->left,nodeRight->right);  
    }
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        solve(root->left,root->right);
        return root;
        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         if(i==size-1){
        //             Node* node=q.front();
        //             q.pop();
        //             if(node->left){
        //                 q.push(node->left);
        //             }
        //             if(node->right){
        //                 q.push(node->right);
        //             }
        //         }else{
        //             Node* node=q.front();
        //             q.pop();
        //             if(node->left){
        //                 q.push(node->left);
        //             }
        //             if(node->right){
        //                 q.push(node->right);
        //             }
        //             Node* node2=q.front();
        //             node->next=node2;
        //             // q.pop();
        //         }
        //     }
        // }
        // return root;
    }
};