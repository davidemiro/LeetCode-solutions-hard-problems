class Solution:
    def binarySearch(self, number: List[int], target):
        l = 0
        r = len(number) - 1
        
        while l <= r:
            q = (l + r) // 2
            if number[q] == target:
                return q
            elif number[q] < target:
                l = q + 1
            else:
                r = q - 1
        return -1
            


    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i,n in enumerate(numbers):
            t = target - n
            if t == n:
                if i > 0 and numbers[i - 1] == n:
                    return [i, i + 1]
                if i < len(numbers) - 1 and numbers[i + 1] == n:
                    return [i + 1, i + 2]
                else:
                    continue
            q = self.binarySearch(numbers, t)
            if q != -1:
                if q > i:
                    return [i + 1, q + 1]
                else:
                    return [q + 1, i + 1]
        
        return [-1, -1]
            


        
        