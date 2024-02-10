class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min,max,maxProfit;
        for(int i = 0; i < prices.size(); i++){
            if(i == 0){
                min = prices[i];
                max = -1;
                maxProfit = 0;
            }
            else{
                if(prices[i] < min){
                    min = prices[i];
                    max = -1;
                }
                if(prices[i] > max && prices[i] > min){
                    max = prices[i];
                    if(max - min > maxProfit){
                        maxProfit = max - min;
                    }
                }
            }
            
        }
        return maxProfit;
        
    }
};