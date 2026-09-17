class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = 1
        zero = 0

        for num in nums:
            if(num != 0):
                prod *= num
            if num == 0:
                zero += 1
            
        if(zero > 1):
            return [0] * len(nums)

        if(zero == 1):
            result = []
            for num in  nums:
                if(num == 0):
                    result.append(prod)
                else:
                    result.append(0)
            return result

        result = []
        for num in nums:
            result.append(prod // num)
        return result

        