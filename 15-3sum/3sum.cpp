#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int binarySearch(int l,int r,int a,vector<int> nums){
        if(l > r){
            return -1;
        }
        else{
            int q = (l + r) /2;
            if (nums[q] == a ) return q;
            else if(nums[q] > a) return binarySearch(l,q-1,a,nums);
            else return binarySearch(q+1,r,a,nums);
        }
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum,k;
        int N = nums.size();
        vector<vector<int>> solutions;
        
        for(int i = 0; i < N - 1; i++){
            if( i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            
            int r = N - 1;
            int l = i + 1;
            while(r > l){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0 && i != r){
                    solutions.push_back({nums[i],nums[l],nums[r]});
                    l ++;
                    while(nums[l] == nums[l - 1] && l < r){
                        l++;
                    }
                }
                else if(sum > 0)
                    r--;
                else
                    l++;
            }
            
        }
        return solutions;
        
    }
};
