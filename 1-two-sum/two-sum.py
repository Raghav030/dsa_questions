class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n= len(nums)
        ans=[]
        for i in range(0,n):
            first_element= nums[i]
            for j in range(i+1, n):
                second_element= nums[j]
                if first_element+ second_element==target:
                    return [i, j]
        
        return 