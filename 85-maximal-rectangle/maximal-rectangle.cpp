class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotonic_stack;
        int max = 0;
        int h,x;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(!monotonic_stack.empty() && heights[monotonic_stack.top()] > heights[i]){
                h = heights[monotonic_stack.top()];
                monotonic_stack.pop();
                if(!monotonic_stack.empty()){
                    x = i - monotonic_stack.top() - 1;
                }
                else{
                    x = i;
                }
                
                h = h*x;
                max = max > h ? max : h;
                
                
                
            
            }
            
            monotonic_stack.push(i);
            
        }
        
        return max;
    
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        int m;
        int max = 0;
        vector<vector<int>> dp;
        dp = vector<vector<int>>(R);
        
        
        for(int i = 0; i < R; i++){
            dp[i] = vector<int>(C);
        }
        
        for(int j = 0; j < C; j++){
            for(int i = 0; i < R; i++){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                
                }
                else{
                    if(i == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                }
            }
        }
        
      
        for(int i = 0; i < R; i++){
            m = largestRectangleArea(dp[i]);
            max = max > m ? max : m;
        }
    
        return max;
        
    }
};