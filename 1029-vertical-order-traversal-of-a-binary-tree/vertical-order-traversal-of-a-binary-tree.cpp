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
    void tree_traversal(TreeNode* root, map<int,vector<vector<int>>>& m, vector<int>& columns,int row,int col){
        if(root == nullptr) return;
        if(m.find(col) == m.end()){
            m[col] = vector<vector<int>>();
            columns.push_back(col);
        }
        
        m[col].push_back({row,root->val});
        tree_traversal(root->left,m,columns,row + 1,col - 1);
        tree_traversal(root->right,m,columns,row + 1,col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        


        
        map<int,vector<vector<int>>> m;
        vector<int> columns;
        tree_traversal(root,m,columns,0,0);
        sort(columns.begin(),columns.end(),[](int a,int b){return a < b;});
        vector<vector<int>> solution(columns.size());
        vector<vector<int>> x;
        for(int i = 0; i < columns.size(); i++){
            x = m[columns[i]];
            sort(x.begin(),x.end(),[](vector<int> a,vector<int> b){
                if(a[0] == b[0]){
                    return a[1] < b[1];
                    
                }
                else{
                    return a[0] < b[0];
                }
                
            });
            for(int j = 0; j < x.size(); j++){
                solution[i].push_back(x[j][1]);
            }
            
            
        }
        return solution;
        
        
        
    }
};