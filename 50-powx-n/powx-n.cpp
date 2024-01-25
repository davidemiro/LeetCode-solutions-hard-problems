class Solution {
public:
    double myPowRecursive(double x,long long n){
        double sol;
        if(n == 1) return x;
        else if(n == 2) return x*x;
        else{
            sol = myPowRecursive(x,n/2);
            if(n % 2 == 0){
                return sol*sol;
            }
            else{
                return sol*sol*x;
            }
        }

    }
    double myPow(double x, int n) {
        long long N = (long long) n;
        if(n < 0){
        
            N = N * -1;
            x = 1 / x;
        }
        if(n == 0) return 1;

        return myPowRecursive(x,N);
        
    }
};