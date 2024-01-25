class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int i =0;
        char c;
        while (true){
            if(strs[0].size() == i){
                return prefix;
            }
            c = strs[0][i];

            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != c){
                    return prefix;
                }
            }
            prefix = prefix + c;
            i++;

        }
        return prefix;
        
    }
};