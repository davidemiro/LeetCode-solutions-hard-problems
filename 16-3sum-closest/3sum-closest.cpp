class Solution {
public:
    void solution(vector<int>& nums, int N, int sum, int p,int target, int& min, int& minSum, int t){
        if(p == N){
            if((abs(target - sum) < min || min == -1) && t == 3){
                min = abs(target - sum);
                minSum = sum;
            }
            return;
        }
        solution(nums, N, sum, p + 1, target, min,minSum, t);
        solution(nums, N, sum + nums[p], p + 1, target, min,minSum,t + 1);


    }
    int threeSumClosest(vector<int>& nums, int target) {
        int min = -1;
        int minSum = -1;
        int sum;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    sum = nums[i] + nums[j] + nums[k];
                    if(abs(target - sum) < min || min == -1){
                        min = abs(target - sum);
                        minSum = sum;

                    }
                }
            }
        }

        return minSum;
        
    }
};