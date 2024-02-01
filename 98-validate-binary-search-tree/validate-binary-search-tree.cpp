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

    map<TreeNode*,int> mapMax;
    map<TreeNode*,int> mapMin;
    int getMax(TreeNode* root, map<TreeNode*,int>& mapMax){
        int v1,v2;
        if(mapMax.find(root) != mapMax.end()){
            return mapMax[root];
        }

        if(root->left != nullptr){
            v1 = getMax(root->left,mapMax);
        }else{
            v1 = root->val;
        }

        if(root->right != nullptr){
            v2 = getMax(root->right,mapMax);
        }else{
            v2 = root->val;
        }

        mapMax[root] = max(max(root->val,v1),v2);

        return mapMax[root];
        
        
            
        
    }

    int getMin(TreeNode* root, map<TreeNode*,int>& mapMin){
        int v1,v2;
        if(mapMin.find(root) != mapMin.end()){
            return mapMin[root];
        }
        
        if(root->left != nullptr){
            v1 = getMin(root->left,mapMin);
        }else{
            v1 = root->val;
        }

        if(root->right != nullptr){
            v2 = getMin(root->right,mapMin);
        }else{
            v2 = root->val;
        }

        mapMin[root] = min(min(root->val,v1),v2);

        return mapMin[root];
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(root->left != nullptr){
            if(getMax(root->left,mapMax) >= root->val) return false;

        }
        if(root->right != nullptr){
            if(getMin(root->right,mapMin) <= root->val) return false;

        }
    
        return isValidBST(root->left) && isValidBST(root->right);
        
    }
};