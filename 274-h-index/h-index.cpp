class Solution {
public:
    int isGE(vector<int>& nums, int m){
        int sol = 0;
        for(int n : nums){
            if(n >= m){
                sol++;
            }
        }
        return sol;
    }
    int hIndex(vector<int>& citations) {
        int maxH;
        int H;
        for(int c : citations){
            H = min(isGE(citations,c),c);
            if(H > maxH){
                maxH = H;
            }
        }

        return maxH;

        

        
    }
};