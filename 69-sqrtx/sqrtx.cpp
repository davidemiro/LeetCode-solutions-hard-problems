class Solution {
public:
    int mySqrt(int x) {
        
        long long l = 0;
        long long r = x / 2 + 1;
        long long q,m,n;
        while(l <= r){
            q = (l + r)/ 2;
            m = q * q;
            n = (q + 1)*(q + 1);
            if(x >= m && x < n) return q;
            else if(x < m) r = q - 1;
            else l = q + 1;
        }
        return -1;
        
        
        
    }
};