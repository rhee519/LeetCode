class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        ans, score = 0, 0
        tokens.sort()
        l, r = 0, len(tokens)-1
        while l <= r:
            if power < tokens[l]:
                if score == 0:
                    break
                else:
                    power += tokens[r]
                    r -= 1
                    score -= 1
            else:
                power -= tokens[l]
                l += 1
                score += 1
                ans = max(ans, score)
        
        return ans