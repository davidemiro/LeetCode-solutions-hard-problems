class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        l_p = 0
        r_p = len(height) - 1
        m = 0
        max_ = 0
        while l_p < r_p:
            m = (r_p - l_p) * min(height[l_p],height[r_p])
            if m > max_:
                max_ = m
            if height[l_p] > height[r_p]:
                r_p -= 1
            else:
                l_p += 1
        
        return max_


        