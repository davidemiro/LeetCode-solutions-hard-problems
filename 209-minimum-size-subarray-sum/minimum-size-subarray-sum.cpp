class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int l = 0;
        int r = -1;
        int min = 0;
        int sum = 0;

        while(l < nums.size()){
            if(r + 1 < nums.size() && sum < target){
                sum += nums[++r];
            }else{
                sum -= nums[l++];
            }
        
            if(sum >= target){
                if(min == 0 || min > r - l + 1){
                    min = r - l + 1;
                }
            }
        }

        return min;        
    }
};