#include <vector>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int T1,T2,T3;
        int i = 1;
        for(int i = 1; i<= n; i++){
            if(i == 1){
                T1 = 1;
                T3 = 1;
            }
            else if(i == 2){
                T2 = 2;
                T3 = 2;
            }
            else{
                T3 = T1 + T2;
                T1 = T2;
                T2 = T3;
            }
            
        }
        return T3;
        
    }
};