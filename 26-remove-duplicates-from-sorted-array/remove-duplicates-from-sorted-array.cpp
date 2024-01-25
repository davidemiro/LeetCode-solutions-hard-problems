class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        if(nums.size() == 0){
            return 0;
        }
        int pre = nums[0];
        int i = 1;
        for(i = 1; i < nums.size();i++){
            if(pre == nums[i]){
                pos ++;
            }else{
                nums[i - pos - 1] = pre;
                pre = nums[i];
            }
            
        }
        nums[i - pos - 1] = pre;
        
        return nums.size() - pos;
        
    }
};