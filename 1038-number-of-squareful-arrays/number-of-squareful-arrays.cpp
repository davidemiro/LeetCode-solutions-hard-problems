class Solution {
public:
    bool isSquare(int n){
        if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
            return true;
        }
        else {
            return false;
        }
    }
    void permutation(int p,int n,vector<pair<int,int>>& backtrack,vector<int> sol,int& N){
        if(p == n){
            N++;
            return;
        }

        for(int i = 0; i < backtrack.size(); i++){


            if(backtrack[i].second > 0){
                if(p > 0){
                    if(!isSquare(sol[p - 1] + backtrack[i].first)){
                        continue;
                    }
                }
                backtrack[i].second--;
                sol[p] = backtrack[i].first;
                permutation(p + 1,n,backtrack,sol,N);
                backtrack[i].second++;
            }
            
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        vector<pair<int,int>> backtrack;
        vector<int> sol(n);
        int N = 0;

        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }
            else{
                m[nums[i]]++;
            }
        }
        for(auto it = m.begin(); it != m.end(); it++){
            backtrack.push_back(pair<int,int>(it->first,it->second));

        }
        permutation(0,n,backtrack,sol,N);

        return N;
        
    }
};