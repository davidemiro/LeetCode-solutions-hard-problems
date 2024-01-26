func findUniquePaths(m int, n int, p int, sol int) int{
    if sol == p{
        return 1
    }else{
        count := 0
        if m > 0{
            count += findUniquePaths(m-1,n,p,sol+1)

        }
        if n > 0{
            count += findUniquePaths(m, n - 1,p,sol+1)
        }

        return count
    }
}

func uniquePaths(m int, n int) int {
    
    dp := make([][] int,m)

    

    for i :=0; i < m; i++{
        dp[i] = make([] int,n)
        for j:=0; j < n;j++{
            if i == 0 && j == 0{
                dp[i][j] = 1
            }else if i == 0{
                dp[i][j] = dp[i][j - 1]
            }else if j == 0{
                dp[i][j] = dp[i - 1][j]
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
            }
        }
    }

    return dp[m - 1][n - 1]

    
    
}
