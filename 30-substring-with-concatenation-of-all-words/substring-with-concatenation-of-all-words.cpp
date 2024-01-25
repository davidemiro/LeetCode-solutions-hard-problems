class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> count_words,c_w;
        vector<int> sol;
        queue<string> q;
        int N = words.size();
        for(string w : words){
            if(count_words.find(w) == count_words.end()){
                count_words[w] = 1;
                c_w[w] = 0;
            }
            else{
                count_words[w]++;
            }
        }
        int count = 0;
        int l = words[0].size();
        int L = s.size();
        int window = l * N;
        string x,k;
        for(int e = 0; e < l; e++){
            for(string w : words){
                c_w[w] = 0;
            }
            q = queue<string>();
            count = 0;
            for(int i = e; i <= L - l; i+=l){
                x = s.substr(i,l);
                if(count_words.find(x) != count_words.end()){
                    c_w[x]++;
                    if(c_w[x] <= count_words[x]){
                    
                        count++;
                        if(count == N){
                            sol.push_back(i + l - window);
                        }
                    }
                }
                q.emplace(x);
                if(i + l >= window){
                    k = q.front();
                    q.pop();
                    if(count_words.find(k) != count_words.end()){
   
                        if(c_w[k] <= count_words[k]){
                            count--;
                        }
                        c_w[k]--;
                    }
                
                
                }
            
            
            
            
            }
            
        }
        
        return sol;
        
        
    }
};