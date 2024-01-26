class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            if(nums[i] == 0){
                if(max_index <= i){
                    
                    return i == N - 1;
                }
                
            }
            else{
                max_index = max(max_index,i + nums[i]);
            }
        }
        return true;
        
    }
};