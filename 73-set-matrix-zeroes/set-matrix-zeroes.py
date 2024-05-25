class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        R = len(matrix)
        C = len(matrix[0])

        rows = [1 for _ in range(R)]
        cols = [1 for _ in range(C)]

        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 0:
                    rows[i] = 0
                    cols[j] = 0
        
        for i in range(R):
            for j in range(C):
                if rows[i] == 0 or cols[j] ==0:
                    matrix[i][j] = 0

        