

func minPathSum(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    dp := make([][] int,m)
    
    for i:=0; i < m; i++{
        dp[i] = make([]int,n)
        for j := 0; j <n; j++{
            if i == 0 && j == 0{
                dp[i][j] = grid[i][j]
            }else if i == 0{
                dp[i][j] = grid[i][j] + dp[i][j - 1]
            }else if j == 0{
                dp[i][j] = grid[i][j] + dp[i - 1][j]
            }else{
                dp[i][j] = int(math.Min(float64(grid[i][j]+dp[i - 1][j]),float64(grid[i][j] + dp[i][j - 1])))
            }

        }
    }

    return dp[m - 1][n - 1]

    
}