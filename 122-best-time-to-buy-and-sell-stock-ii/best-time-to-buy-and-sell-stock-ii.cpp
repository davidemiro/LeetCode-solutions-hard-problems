class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int maxProfit = 0;
        for(int i = 1; i < N; i++){
            if(prices[i] - prices[i - 1] > 0){
                maxProfit += (prices[i] -prices[i - 1]);
            }

        }
        
        return maxProfit;
        
        
    }
};