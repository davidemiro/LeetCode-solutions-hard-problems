class Solution {
public:
    bool computePath(int stone,int k,map<int,int>& m,map<string,bool>& memoization,int N){
        
        if(stone == N) return true;
        stringstream ss;
        ss << k << "_" << stone;
        if(memoization.find(ss.str()) != memoization.end()){
            return false;
        }

        if(k - 1 > 0 && m.find(stone + k - 1) != m.end() && stone + k - 1 > stone){
            if(computePath(stone + k - 1, k - 1, m,memoization, N)){
                return true;
            }
            stringstream ss;
            ss << k << "_" << stone;
            memoization[ss.str()] = false;
        }
        if(m.find(stone + k) != m.end() && stone + k  != stone){
            if(computePath(stone + k, k, m,memoization, N)){
                return true;
            }
            stringstream ss;
            ss << k << "_" << stone;
            memoization[ss.str()] = false;
        }
        if(m.find(stone + k + 1) != m.end()&& stone + k + 1 != stone){
            if(computePath(stone + k + 1, k + 1, m,memoization, N)){
                return true;
            }
            stringstream ss;
            ss << k << "_" << stone;
            memoization[ss.str()] = false;
        }


        return false;
        

    }
    bool canCross(vector<int>& stones) {
        map<int,int> m;
        map<string,bool> memoization;
        int N = stones.size();
        for(int i = 0; i < N; i++){
            m[stones[i]] = i;
        }

        return computePath(0,0,m,memoization,stones[stones.size() - 1]);
        
    }
};