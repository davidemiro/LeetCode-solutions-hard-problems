class Solution {
public:
    int wordDist(string& beginWord, string& endWord){
        int L = beginWord.size();
        int sol = 0;
        for(int i = 0; i < L; i++){
            if(beginWord[i] != endWord[i]){
                sol++;
            }

        }
        return sol;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int N = wordList.size();
        int L = wordList[0].size();
        vector<vector<int>> graph(N);
        vector<bool> visited(N,false);
        queue<pair<int,int>> q;
        pair<int,int> node;
        int min = -1;
        

        for(int i = 0; i < N; i++){
            if(wordDist(wordList[i],beginWord) == 1){
                q.push({i,1});
                visited[i] = true;
            }
            for(int j = i + 1; j < N; j++){
                if(wordDist(wordList[i],wordList[j]) == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(wordDist(wordList[node.first],endWord) == 0){
                if(node.second < min || min == -1){
                    min = node.second;
                }
            }
            else{
                for(int x : graph[node.first]){
                    if(!visited[x]){
                        q.push({x, node.second + 1});
                        visited[x] = true;
                    }
                }
            }
        }
        
        return min + 1;
    }
};