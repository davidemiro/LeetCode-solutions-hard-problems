class Solution {
public:
    void combination_sum(vector<int>& candidates, int target, vector<int> s, int sum, int p, vector<vector<int>>& sols){
        if(sum == target){
            vector<int> sol;
            for(int i  = 0; i < candidates.size(); i++){
                for(int j = 0; j < s[i]; j++){
                    sol.push_back(candidates[i]);

                }
            }
            sols.push_back(sol);
            return;
        }else if(p >= candidates.size()){
            return;
        }
        else if(sum > target){
            return;
        }
        else{
            for(int i = 0; i < target; i++){
                s[p] = i;
                combination_sum(candidates,target,s, sum, p + 1, sols);
                sum += candidates[p];

            }

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sols;
        vector<int> s(candidates.size());
        for(int i = 0; i < candidates.size(); i++){
            s[i] = 0;
        }

        combination_sum(candidates, target, s, 0,0, sols);
        return sols;
        
    }
};