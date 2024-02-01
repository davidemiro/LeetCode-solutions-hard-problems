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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isSym(root->left,root->right);
        
    }
    
    bool isSym(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        else if(left != nullptr && right != nullptr){
            if(left->val != right->val) return false;
            return isSym(left->right,right->left) && isSym(left->left,right->right); 
        }
        else 
            return false;
            
    }
    vector<int> leftTraversal(TreeNode* root) {
        vector<int> nodes;
        vector<int> returnNodes;
        
        if(root == NULL){
            return nodes;
        }
        
        nodes.push_back(root->val);
        if(root->left != NULL){
            returnNodes = leftTraversal(root->left);
            for(int i : returnNodes)
                nodes.push_back(i);
            
        }
        else{
            nodes.push_back(-1);
        }
        

        if(root->right != NULL){
            returnNodes = leftTraversal(root->right);
            for(int i : returnNodes)
                nodes.push_back(i);
        }
        else{
            nodes.push_back(-1);
        }
        return nodes;
        
    }
    vector<int> rightTraversal(TreeNode* root) {
        vector<int> nodes;
        vector<int> returnNodes;
        
        if(root == NULL){
            nodes.push_back(-1);
            return nodes;
        }
        
        nodes.push_back(root->val);
        
        if(root->right != NULL){
            returnNodes = rightTraversal(root->right);
            for(int i : returnNodes)
                nodes.push_back(i);
        }
        else{
            nodes.push_back(-1);
        }
        if(root->left != NULL){
            returnNodes = rightTraversal(root->left);
            for(int i : returnNodes)
                nodes.push_back(i);
            
        }
        else{
            nodes.push_back(-1);
        }
        

        
        return nodes;
        
    }
};