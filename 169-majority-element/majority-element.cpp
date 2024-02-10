#include <map>
#include <vector>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int sum = 0;
        for(int i = 0; i <nums.size();i++){
            if(sum == 0){
                candidate = nums[i];
            }
            if(candidate == nums[i]){
                sum += 1;
            }
            else{
                sum -= 1;
            }
        }
        return candidate;
    }
};