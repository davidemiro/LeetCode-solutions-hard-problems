class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1) return true;
        vector<bool> visited(n);
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < n; i++){
            graph[i] = vector<int>();
            visited[i] = false;
        }
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(source, destination, n, visited, graph);
        
        
    }
    bool dfs(int s,int d, int n, vector<bool>& visited,vector<vector<int>>& graph){
        visited[s] = true;
        for(int v : graph[s]){
            if(v == d) return true;
            if(!visited[v]){
                if(dfs(v,d,n,visited,graph)){
                    return true;
                }
            }
        }
        return false;
        
    }
};