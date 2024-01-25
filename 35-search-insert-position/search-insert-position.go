func searchInsert(nums []int, target int) int {
    l := 0
    r := len(nums) - 1

    for l <= r{
        q := (l + r)/2
        if nums[q] == target{
            return q
        }else if nums[q] < target{
            l = q + 1
            if q + 1 == len(nums){
                return q + 1
            }
            if nums[q + 1] > target{
                return q + 1
            }
        }else{
            r = q - 1
            if q - 1 < 0{
                return 0
            }
            if nums[q - 1] < target{
                return q
            }
        }
    }
    return -1
    
}