class Solution {
public:
    bool checkAndUpdate(char s, char t, map<char,char>& m){
        if(m.find(s) == m.end()){
            m[s] = t;
            return true;
        }else{
            return m[s] == t;
        }

        
    }
    

    bool isIsomorphic(string s, string t) {
        map<char,char> s_m;
        map<char,char> t_m;
        int N = s.size();
        for(int i = 0; i < N; i++){
            if(!checkAndUpdate(s[i],t[i],s_m) || !checkAndUpdate(t[i],s[i],t_m)){
                return false;
            } 
        }
        return true;

        
        
    }
};

