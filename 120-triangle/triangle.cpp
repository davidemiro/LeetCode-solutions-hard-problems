class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        int sol = 0;
        

        for(int i = 0; i < triangle.size(); i++){
            dp[i] = vector<int>(i + 1);
            if(i == 0){
                dp[i][0] = triangle[i][0];
                if(i == triangle.size() - 1){
                    sol = dp[i][0];
                }
            }else{
                for(int j = 0; j < triangle[i].size(); j++){
                    if(j == 0){
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    }else if(j == triangle[i].size() - 1){
                        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                        
                    }else{
                        dp[i][j] = min(dp[i - 1][j],dp[i - 1][j - 1]) + triangle[i][j];
                    }

                    if(i == triangle.size() - 1){
                        if(j == 0){
                            sol = dp[i][j];
                        }
                        else{
                            sol = sol > dp[i][j] ? dp[i][j] : sol;
                        }
                    }
                }
            }
        }

        return sol;

        
        
    }
};