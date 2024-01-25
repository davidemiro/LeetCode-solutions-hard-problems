class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
        vector<int> stack(N + 1);
        stack[0] = 0;
        int p = 0;
        int max = 0;
        for(char c : s){
            if(c == '('){
                p++;
                stack[p] = 0;
                
            }
            else{
                if(p == 0){
                    stack[0] = 0;
                }
                else{
                    stack[p - 1] = stack[p - 1] + stack[p] + 2;
                    if(stack[p - 1] > max){
                        max = stack[p - 1];
                    }
                    p--;
                    
                }
            }
        }
        
        return max;
        
    }
};