func maxProfitLeft(prices [] int) []int{
    min := -1
    max := -1
    dp := make([] int, len(prices),len(prices))
    m := 0
    for i := 0; i < len(prices); i++{
        if min == -1 || prices[min] > prices[i]{
            min = i
            max = -1
        }
        if max == -1 || prices[max] < prices[i]{
            max = i
        }
        if m < prices[max] - prices[min]{
            m = prices[max] - prices[min]
        }
        dp[i] = m

    }
    return dp
}

func maxProfitRight(prices [] int) []int{
    min := -1
    max := -1
    dp := make([] int, len(prices),len(prices))
    m := 0

    for i := len(prices) - 1; i >= 0; i--{
        if max == -1 || prices[max] < prices[i]{
            max = i
            min = -1
        }
        if min == -1 || prices[min] > prices[i]{
            min = i
        }
        if m < prices[max] - prices[min]{
            m = prices[max] - prices[min]
        }
        dp[i] = m

    }
    return dp 
}




func maxProfit(prices []int) int {

    N := len(prices)

    if N == 1{
        return 0
    }

    dp_r := maxProfitRight(prices)
    dp_l := maxProfitLeft(prices)
    max := 0
    for i := 0; i < N; i++{
        if i == N - 1{
            if max < dp_l[i]{
                max = dp_l[i]
                
            }
            continue
        }
        if dp_l[i] + dp_r[i + 1] > max{
            max = dp_l[i] + dp_r[i + 1]
        }
    }

    return max

}
