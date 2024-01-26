class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        for(int i = 0; i < n; i++){
            matrix[i] = vector<int>(n);
        }
        int ph = 0;
        int r = 0;
        int c = 0;
        int k = 0;
        for(int i = 1; i <= n*n;i++){
            matrix[r][c] = i;
            if(ph == 0){
                c++;
                if(c == n - 1 - k){
                    ph += 1;
                }
            }
            else if(ph == 1){
                r++;
                if(r == n - 1 - k){
                    ph += 1;
                    
                }
                
            }
            else if(ph == 2){
                c--;
                if(c == k){
                    ph+=1;
                }
            }
            else{
                r--;
                if(r == k + 1){
                    ph = 0;
                    k++;
                }
                
            }
            
        }
        return matrix;
    }
};
