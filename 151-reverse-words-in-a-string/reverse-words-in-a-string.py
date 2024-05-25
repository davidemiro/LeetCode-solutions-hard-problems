class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        x = [c for c in s.split(" ") if c != '']
        x.reverse()
        return " ".join(x)



        