class Solution(object):
    def subarraysWithKDistinct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return self.sub(nums,k) - self.sub(nums, k - 1)

    def sub(self,nums,k):
        m = {}
        p = 0
        sol = 0

        for i,n in enumerate(nums):
            if n not in m:
                m[n] = 1
                while len(m) > k:
                    m[nums[p]] -= 1
                    if m[nums[p]] == 0:
                        del m[nums[p]]
                    p += 1
            else:
                m[n] += 1

            sol += (i - p + 1)
        
        return sol

