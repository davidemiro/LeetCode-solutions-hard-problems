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
    void solFunction(TreeNode* root,int level,vector<vector<int>>& sol){
        if(root == nullptr) return;
        if(sol.size() < level){
            sol.push_back(vector<int>());
        }
        solFunction(root->left,level + 1,sol);
        solFunction(root->right,level + 1,sol); 
        
        sol[level - 1].push_back(root->val);
        

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level = 1;
        vector<vector<int>> sol;
        solFunction(root,level,sol);

        reverse(sol.begin(),sol.end());
        return sol;
        
    }
};