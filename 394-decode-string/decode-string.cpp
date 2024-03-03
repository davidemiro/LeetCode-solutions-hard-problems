class Solution {
public:
    int getNum(int& p, string& s){
        string num = "";
        while(p < s.size()){
            if(s[p] >= '0' && s[p] <= '9'){
                num += s[p];
                p++;
            }
            else{
                break;
            }
        }
        return stoi(num);
    }
    string decodeStringRec(int& p,string& s){
        int m = 1;
        string sub;
        string curr;
        while(p < s.size()){
            if(s[p] >= '0' && s[p] <= '9'){
                m = getNum(p,s);
                continue;
            }
            else if (s[p] == '['){
                p++;
                sub = decodeStringRec(p,s);
                for(int i = 0; i < m; i++){
                    curr += sub;
                }
                p++;
            }else if (s[p] == ']'){
                return curr;
            }else{
                curr += s[p];
                p++;
            }
            
        }
        return curr;
    }
    string decodeString(string s) {
        int p = 0;
        
        return decodeStringRec(p,s);
        
    }
};