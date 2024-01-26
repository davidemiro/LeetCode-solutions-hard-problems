class Solution {
public:
    bool getPermutation(string pe,int p,vector<int>& bk,int& k,int kt,int n, string& s){
        if(p == n){
            k++;
            if(k == kt){
                s = pe;
                return true;
            }
            else{
                return false;
            }
        }
        for(int i = 0; i < n; i++){
            if(bk[i] == 0){
                char c = '0' + i + 1;
                bk[i] = 1;
                if(getPermutation(pe + c,p + 1,bk,k,kt,n,s)){
                    return true;
                }
                bk[i] = 0;
                
            }
            
        }
        return false;
    }
    string getPermutation(int n, int k) {
        vector<int> bk(n);
        string sol;
        int kt = 0;
        for(int i = 0; i < n; i++){
            bk[i] = 0;
        }
        
        getPermutation("",0,bk,kt,k,n,sol);
        return sol;
        
    }
};