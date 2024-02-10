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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return findPathSum(root,targetSum,0);
        
    }
    
    bool findPathSum(TreeNode* root,int targetSum,int currentSum){
        if(root != nullptr)
            currentSum += root->val;
        else
            return false; 
        if(currentSum == targetSum && root->left == nullptr && root->right == nullptr){
            return true;
        }
        else{
            if(findPathSum(root->left,targetSum,currentSum)) return true;
            else if(findPathSum(root->right,targetSum,currentSum)) return true;
            else return false;
        }
        
        
        
        
    }
};