class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        vector<vector<bool>> dp(N + 1);
        string sb;
        dp[0] = vector<bool>(N);
        for(int i = 0; i < N; i++){
            dp[0][i] = true;
        }
        for(int i = 1; i <= N; i++){
            dp[i] = vector<bool>(N);
            dp[i][0] = false;
            for(int j = 0; j < i; j++){
                sb = s.substr(j,i - j);
                
                for(string w : wordDict){
                    if(sb == w){
                        
                        if(j == 0){
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = true;
                            dp[i][0] = dp[i][0] | (dp[i][j] & dp[j][0]);
                            
                        }
                        if(dp[i][0] == true && i == N){
                            return true;
                        }
                        break;
                    }
                    else
                        dp[i][j] = false;
                }
                
            
                
            }
        }
        return false;
    }
};