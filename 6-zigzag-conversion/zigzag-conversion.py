class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = [[] for _ in range(numRows)]
        row = 0
        i = 1
        if numRows == 1:
            return s
        for c in s:
            rows[row].append(c)
            row += i
            if row == numRows - 1:
                i = -1
            if row == 0:
                i = 1
        rows = ["".join(r) for r in rows]
        return "".join(rows)

            

        