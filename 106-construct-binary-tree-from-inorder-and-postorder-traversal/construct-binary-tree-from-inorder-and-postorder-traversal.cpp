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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        TreeNode* tree = build_tree(inorder,postorder, 0,n,0,n);
        
        return tree;
    

        
        
    }
    int linearSearch(vector<int> v, int target){
        int s = -1;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == target){
                s = i;
                break;
            } 
        }
        return s;
        
    }
    TreeNode* build_tree(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd, int postStart, int postEnd){
        
        if(inStart > inEnd || postStart > postEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int index = linearSearch(inorder, postorder[postEnd]);
        root->left = build_tree(inorder, postorder, inStart, index - 1, postStart, postEnd - (inEnd - index) - 1);
        root->right = build_tree(inorder, postorder, index + 1, inEnd, postEnd - (inEnd - index), postEnd - 1);
        return root;
        
        
        
        
        
        
    }
};

