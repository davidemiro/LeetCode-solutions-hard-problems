class Solution {
public:
    bool dfs(int i, int j, int p, int L,int R, int C, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(i + 1  < R && board[i + 1][j] == word[p] && !visited[i + 1][j]){
            if(p == L - 1) return true;
            else{
                visited[i + 1][j] = true;
                if(dfs(i + 1, j, p + 1, L, R, C, word, board, visited)){
                    return true;
                }
                visited[i + 1][j] = false;
            }
        }

        if(j + 1  < C && board[i][j + 1] == word[p] && !visited[i][j + 1]){
            if(p == L - 1) return true;
            else{
                visited[i][j + 1] = true;
                if(dfs(i, j + 1, p + 1, L, R, C, word, board, visited)){
                    return true;
                }
                visited[i][j + 1] = false;
            }
        }

        if(i - 1  >= 0 && board[i - 1][j] == word[p] && !visited[i - 1][j]){
            if(p == L - 1) return true;
            else{
                visited[i - 1][j] = true;
                if(dfs(i - 1, j, p + 1, L, R, C, word, board, visited)){
                    return true;
                }
                visited[i - 1][j] = false;
            }
        }

        if(j - 1  >= 0 && board[i][j - 1] == word[p] && !visited[i][j - 1]){
            if(p == L - 1) return true;
            else{
                visited[i][j - 1] = true;
                if(dfs(i, j - 1, p + 1, L, R, C, word, board, visited)){
                    return true;
                }
                visited[i][j - 1] = false;
            }
        }

        return false;
    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int N = board.size();
        int M = board[0].size();
        int L = word.size();
        vector<vector<bool>> visited(N);
        for(int i = 0; i < N; i++){
            visited[i] = vector<bool>(M);
            fill(visited[i].begin(),visited[i].end(),false);
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == word[0]){
                    if(L == 1) return true;
                    visited[i][j] = true;
                    if(dfs(i,j,1,L,N,M,word, board,visited)){
                        return true;

                    }
                    visited[i][j] = false;
                }
            }
        }

        return false;

        
    }
};