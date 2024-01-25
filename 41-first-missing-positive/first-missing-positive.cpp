class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        map<int,int> ex;
        for(int n : nums){
            ex[n] = n; 
            if(n == missing){
                while(ex.find(missing) != ex.end()){
                    missing++;
                }
                
            }
        }
        
        return missing;
        
    }
};