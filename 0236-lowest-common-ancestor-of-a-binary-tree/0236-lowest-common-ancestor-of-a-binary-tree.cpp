/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, TreeNode* node,vector<TreeNode*>& arr){
        if(!root){
            return false ;
        }
        arr.push_back(root);
        if(root->val==node->val){
            return true;
        }
        if(solve(root->left,node,arr) || solve(root->right,node,arr)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //brute force
        vector<TreeNode*> path1, path2;

        if (!solve(root, p, path1) || !solve(root, q, path2)) {
            return nullptr;
        }

        int i;
        for (i = 0; i < path1.size() && i < path2.size(); ++i) {
            if (path1[i] != path2[i]) {
                break;
            }
        }

        return path1[i-1];
    }
};