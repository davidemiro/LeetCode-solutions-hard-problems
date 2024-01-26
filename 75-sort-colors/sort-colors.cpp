class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            switch(nums[i]){
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                default:
                    break;
            }
            
            
        }
        for(int i = 0; i < N; i++){
            if(red != 0){
                nums[i] = 0;
                red --;
            }
            else if(white != 0){
                nums[i] = 1;
                white--;
            }
            else{
                nums[i] = 2;
                
            }
        }
        
    }
};