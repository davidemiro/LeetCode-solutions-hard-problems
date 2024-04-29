class Solution(object):
    def merge(self,a,b,e):
        s = []
        for x in a:
            for y in b:
                s.append(y + x)
                if e:
                    s.append(x + y)
        return s


    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        dp = [[] for _ in range(n + 1)]
        dp[0] = []
        dp[1] = ["()"]
        for k in range(2,n + 1):
            for i in range(1,k):
                for j in range(i , k):
                    if i + j == k:
                        m = self.merge(dp[i],dp[j], i != j)
                        for x in m:
                            if x not in dp[k]:
                                dp[k].append(x)
            dp[k] = dp[k] + ["("+x+")" for x in dp[k - 1]]
        
        return dp[n]

        