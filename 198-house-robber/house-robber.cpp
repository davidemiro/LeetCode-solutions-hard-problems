class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> solutions(N);
        solutions[0] = nums[0];
        if(N == 1) return solutions[0];
        solutions[1] = max(solutions[0],nums[1]);
        for(int i = 2; i < N; i++){
            solutions[i] = max(solutions[i - 1], solutions[i - 2] + nums[i]);
        }
        return solutions[N - 1];
        
    }
};