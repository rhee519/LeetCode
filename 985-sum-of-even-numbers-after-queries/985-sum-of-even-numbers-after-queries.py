class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        even_sum = sum(filter(lambda x: x%2 == 0, nums))
        # print(even_sum)
        for diff, i in queries:
            if nums[i]%2 == 0:
                even_sum -= nums[i]
            nums[i] += diff
            if nums[i]%2 == 0:
                even_sum += nums[i]
            ans.append(even_sum)
        
        return ans