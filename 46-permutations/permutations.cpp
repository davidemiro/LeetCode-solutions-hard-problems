class Solution {
public:
    void permutation(int p,vector<int>& backtrack,vector<int> sol,vector<int>& nums,vector<vector<int>>& solutions){
        if(p == nums.size()){
            solutions.push_back(sol);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!backtrack[i]){
                backtrack[i] = 1;
                sol[p] = nums[i];
                permutation(p + 1,backtrack,sol,nums,solutions);
                backtrack[i] = 0;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> backtrack(n);
        vector<int> sol(n);
        vector<vector<int>> solutions;

        for(int i = 0; i < n; i++){
            backtrack[i] = 0;
        }
        permutation(0,backtrack,sol,nums,solutions);

        return solutions;

        
        
    }
};