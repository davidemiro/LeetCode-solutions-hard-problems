class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """

        
        s1 = "".join(word1)
        s2 = "".join(word2)

        return s1 == s2
        