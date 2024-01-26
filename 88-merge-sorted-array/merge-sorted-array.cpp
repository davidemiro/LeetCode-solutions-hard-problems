class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j;
        i = 0;
        j = 0;
        vector<int> merge;
        
        while(i < m || j < n){
            if(i >= m){
                merge.push_back(nums2[j]);
                j++;
            }
            else if(j >= n){
                merge.push_back(nums1[i]);
                i++;
            }
            else{
                if(nums1[i] <= nums2[j]){
                    merge.push_back(nums1[i]);
                    i++;
                }
                else{
                    merge.push_back(nums2[j]);
                    j++;
                    
                }
            }
            
        }
        nums1 = merge; 
        
    }
};