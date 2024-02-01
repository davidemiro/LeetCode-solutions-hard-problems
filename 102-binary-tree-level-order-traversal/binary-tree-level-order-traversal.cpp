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
    void getLevels(TreeNode* root,int depth,vector<vector<int>>& levels){
        if(root == nullptr)
            return;
        else{
            if(levels.size() <= depth){
                vector<int> v;
                v.push_back(root->val);
                levels.push_back(v);
            }
            else{
                levels[depth].push_back(root->val);
            }
            getLevels(root->left,depth + 1,levels);
            getLevels(root->right,depth + 1,levels);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        getLevels(root,0,levels);
        
        return levels;
    }
};