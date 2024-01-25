class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isFirst){
        int l = 0;
        int r = nums.size() -1;
        int q;
        while(l <= r){
            q = (r+l)/2;
            if(nums[q] > target){
                r = q - 1;

            }else if(nums[q] < target){
                l = q + 1;

            }else{
                if(isFirst){
                    if(q == 0 && nums[q] == target) return q;
                    else if(q > 0 && nums[q - 1] == target){
                        r = q - 1;
                    }
                    else{
                        return q;
                    }
                }else{
                    if(q == nums.size() - 1 && nums[q] == target) return q;
                    if(q < nums.size() && nums[q + 1] == target){
                        l = q + 1;
                    }
                    else{
                        return q;
                    }

                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol;
        sol.push_back(binarySearch(nums,target,true));
        sol.push_back(binarySearch(nums,target,false));

        return sol;  


        
    }
};