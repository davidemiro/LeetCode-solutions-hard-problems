class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        found = False
        i = 0

        if s == "":
            return True
        
        for c in s:
            found = False
            while i < len(t):
                if c == t[i]:
                    found = True
                    i += 1
                    break
                i += 1
        
        

        return found
                
            
        
                
            
        