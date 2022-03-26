class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left, right = 0, len(people)-1
        ans = 0
        while left < right:
            if people[left] + people[right] <= limit:
                ans += 1
                left += 1
                right -= 1
            else:
                ans += 1
                right -= 1
        
        # the last man in the middle exists
        if left == right:
            ans += 1
        return ans