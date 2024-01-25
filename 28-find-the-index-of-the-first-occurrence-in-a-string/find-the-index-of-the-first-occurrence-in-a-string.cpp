class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = haystack.size();
        int L = needle.size();
        for (int i = 0; i <= N - L; ++i) {
        int j;
            for (j = 0; j < L; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == L) {
                return i; 
            }
        }
        return -1;
    }
};