class Solution(object):
    def removeBackspace(self,s):
        c = 0
        x = ""
        for i in range(len(s) - 1,-1,-1):
            if s[i] == '#':
                c += 1
            else:
                if c > 0:
                    c -= 1
                elif c == 0:
                    x = s[i] + x
        return x
 
                
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return self.removeBackspace(t) == self.removeBackspace(s)
        