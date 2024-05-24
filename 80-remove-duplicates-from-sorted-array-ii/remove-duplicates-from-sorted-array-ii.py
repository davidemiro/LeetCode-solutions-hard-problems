class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 1
        current = nums[0]
        N = len(nums)
        read = 1
        write = 0

        while read < N:
            nums[write] = current
            if nums[read] == current:
                count +=1
            else:
                count = 1
                current = nums[read]
            if count <= 2:
                write +=1
            read += 1
        nums[write] = current
        
        
        return write + 1



        