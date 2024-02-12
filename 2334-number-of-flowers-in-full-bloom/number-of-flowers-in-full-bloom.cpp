class Solution {
public:
    int binary_search(vector<int>& v,int x){
        int r = v.size() - 1;
        int l = 0;
        int n = v.size();
        int q;
        while(r >= l){
            q = (l + r) / 2;
            if(v[q] <= x){
                if(q == n - 1){
                    return q;
                }
                else{
                    if(v[q + 1] > x){
                        return q;
                    }
                    else{
                        l = q + 1;
                    }
                }
            }
            else{
                r = q - 1;
            }
        }
        return -1;
        
    }
    
        int binary_search_2(vector<int>& v,int x){
        int r = v.size() - 1;
        int l = 0;
        int n = v.size();
        int q;
        while(r >= l){
            q = (l + r) / 2;
            if(v[q] < x){
                if(q == n - 1){
                    return q;
                }
                else{
                    if(v[q + 1] >= x){
                        return q;
                    }
                    else{
                        l = q + 1;
                    }
                }
            }
            else{
                r = q - 1;
            }
        }
        return -1;
        
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int N = flowers.size();
        vector<int> bloom_start(N);
        vector<int> bloom_end(N);
        vector<int> sol;
        int x1,x2,x;
        
        for(int i = 0; i < N; i++){
            bloom_start[i] = flowers[i][0];
            bloom_end[i] = flowers[i][1];
        }
        sort(bloom_start.begin(),bloom_start.end(),[](int a,int b){return a < b;});
        sort(bloom_end.begin(),bloom_end.end(),[](int a,int b){return a < b;});
        for(int p : persons){
            x1 = binary_search(bloom_start,p) + 1;
            x2 = binary_search_2(bloom_end,p) + 1;
            x = x1 - x2;
            if(x < 0) sol.push_back(0);
            else sol.push_back(x);
        
            
        }
        return sol;
        
    }
};