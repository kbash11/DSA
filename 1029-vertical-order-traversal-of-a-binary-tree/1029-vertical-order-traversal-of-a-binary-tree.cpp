/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<tuple<TreeNode*,int,int>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({root,0,0});
        while(!q.empty()){
            auto [node,vert,level]=q.front();
            q.pop();
            
            m[vert][level].insert(node->val);
        
            if(node->left){
                q.push({node->left,vert-1,level+1});
            }
            if(node->right){
                q.push({node->right,vert+1,level+1});
            }
        }
        for(auto it:m){
            vector<int> arr;
            for(auto it2:it.second){
                for(auto it3:it2.second){
                    arr.push_back(it3);
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};