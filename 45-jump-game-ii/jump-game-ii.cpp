class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int k = 1;
        int m = nums[0];
        int N = nums.size();
        int M = nums[0];
        int new_i,new_M;
        if(N == 1) return 0;
        
        
        while(M < N - 1){
            new_M = 0;
            for(int j = i; j <= M; j++){
                if(nums[j] + j > new_M){
                    new_i = j;
                    new_M = nums[j] + j;
                }
            }
            i = new_i;
            M = new_M;
            k ++;
            
            
        }
        return k;
        
    }
};
