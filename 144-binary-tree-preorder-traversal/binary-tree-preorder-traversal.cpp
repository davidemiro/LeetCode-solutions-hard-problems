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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        vector<int> returnNodes;
        
        if(root == NULL)
            return nodes;


        nodes.push_back(root->val);
        if(root->left != NULL){
            returnNodes = preorderTraversal(root->left);
            for(int i : returnNodes)
                nodes.push_back(i);
            
        }

        if(root->right != NULL){
            returnNodes = preorderTraversal(root->right);
            for(int i : returnNodes)
                nodes.push_back(i);
        }
    return nodes;
        
    }
};