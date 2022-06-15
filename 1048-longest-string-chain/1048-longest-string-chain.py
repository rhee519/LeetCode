class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        ans = 0
        memo = {"": 0}
        words.sort(key=lambda x: len(x))
        for word in words:
            memo[word] = 1
            for i in range(len(word)):
                sub = word[:i] + word[i+1:]
                if sub in memo:
                    memo[word] = max(memo[word], memo[sub]+1)
            ans = max(ans, memo[word])
        return ans