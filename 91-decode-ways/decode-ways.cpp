class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int d;
        vector<int> combinable(n);
        vector<int> notCombinable(n);
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(s[i] == '0'){
                    return 0;
                }
                else{
                    combinable[i] = 1;
                    notCombinable[i] = 0;
                }
            }
            else{
                
                d = (s[i - 1] - '0')*10 + (s[i] - '0');
                if(d == 0) return 0;
                if(d > 26 && s[i] == '0') return 0;
                
                if(d > 26 || s[i - 1] == '0'){
                    
                    combinable[i] = combinable[i - 1] + notCombinable[i - 1];
                    notCombinable[i] = 0;
                }
                else{
                    if(s[i] == '0'){
                        
                        combinable[i] = 0;
                        notCombinable[i] = combinable[i - 1];
                    }
                    else{
                        combinable[i] = combinable[i - 1] + notCombinable[i - 1];
                        notCombinable[i] = combinable[i - 1];
                        
                    }
                    
                    
                }
                
                
            }
            
        }
        
        
        return combinable[n - 1] + notCombinable[n - 1];
        /*
        2
        2 2 | 22
        2 2 6 | 2 26 | 22 6
        2 2 6 2 | 2 26 2 | 22 6 2 |
        2 2 6 2 3 | 2 26 2 3 | 22 6 2 3 | 22 6 23 | 2 26 23 |
        */

        
        
    }
};