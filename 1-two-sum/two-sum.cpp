class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a(nums.size());
        for(int i = 0; i < nums.size();i++){
            a[i] = pair<int,int>(nums[i],i);
            
        
        }
        
        sort(a.begin(),a.end(),[](pair<int,int> a,pair<int,int> b){ return a.first < b.first; });
        int q;
        for(int i = 0; i < a.size();i++){
            q = binarySearch(i + 1,a.size() - 1,target - a[i].first,a);
            if(q != -1){
                return {a[i].second,q}; 
                
            }
            
        }
        return {0,0};
        
    }
    int binarySearch(int l,int r,int t,vector<pair<int,int>>& nums){
        if(l > r) return -1;
        int q = (l + r) / 2;
        
        if(nums[q].first < t){
            return binarySearch(q + 1,r,t,nums);
        }
        else if(nums[q].first > t){
            return binarySearch(l,q - 1,t,nums);
        }
        else return nums[q].second;
    }
};