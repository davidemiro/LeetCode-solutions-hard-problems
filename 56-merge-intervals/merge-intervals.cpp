class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
           return a[0] < b[0]; 
        });
        int N = intervals.size();
        if(N == 0) return intervals;
        int M = 0;
        vector<int> newInterval(2);
        vector<vector<int>> newIntervals;
        for(int i = 0; i < N; i++){
            if(i == N - 1)
                newIntervals.push_back(intervals[i]);
            else{
                if(intervals[i + 1][0] <= intervals[i][1]){
                    
                    intervals[i + 1][0] = intervals[i][0];
                    intervals[i + 1][1] = max(intervals[i][1],intervals[i + 1][1]);
                }
                else
                    newIntervals.push_back(intervals[i]);
            }
        }
        
        return newIntervals;
        
        
    }
};