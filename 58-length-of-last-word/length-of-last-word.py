class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len([w for w in s.split(" ") if w != ""][-1])
        