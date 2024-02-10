func canCompleteCircuit(gas []int, cost []int) int {
    n := len(gas)
    sol := -1
    max := 0
    for i := 0; i < n; i+=1 {
        gas[i] -= cost[i]
    }
    for i := n - 2; i >= 0; i-=1{
        gas[i] +=gas[i + 1]
    }
    if gas[0] < 0{
        return sol
    }
    for i := 0; i <n; i+=1{
        if gas[i] >= max{
            sol = i
            max = gas[i]
        }
    }
    return sol
}