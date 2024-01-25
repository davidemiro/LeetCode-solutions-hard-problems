class Solution {
public:
    void permutation(int p,int n,vector<pair<int,int>>& backtrack,vector<int> sol,vector<vector<int>>& solutions){
        if(p == n){
            solutions.push_back(sol);
            return;
        }

        for(int i = 0; i < backtrack.size(); i++){

            if(backtrack[i].second > 0){
                backtrack[i].second--;
                sol[p] = backtrack[i].first;
                permutation(p + 1,n,backtrack,sol,solutions);
                backtrack[i].second++;
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        vector<pair<int,int>> backtrack;
        vector<int> sol(n);
        vector<vector<int>> solutions;

        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }
            else{
                m[nums[i]]++;
            }
        }
        for(auto it = m.begin(); it != m.end(); it++){
            backtrack.push_back(pair<int,int>(it->first,it->second));

        }
        permutation(0,n,backtrack,sol,solutions);

        return solutions;
        
    }
};