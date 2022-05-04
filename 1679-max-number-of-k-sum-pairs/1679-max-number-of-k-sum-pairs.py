class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        counter = Counter(nums)
        keys = set(counter)
        
        for key in keys:
            num_pairs = min(counter[key], counter[k-key])
            if key == k-key:
                num_pairs //= 2
            ans += num_pairs
            counter[key] -= num_pairs
            counter[k-key] -= num_pairs
            
        return ans