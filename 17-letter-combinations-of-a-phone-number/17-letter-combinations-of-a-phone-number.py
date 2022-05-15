class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        
        numkey = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz",
        }
        
        q = deque([d for d in numkey[digits[0]]])
        for i in range(1, len(digits)):
            letters = numkey[digits[i]]
            
            while len(q[0]) <= i:
                typed = q.popleft()

                for letter in letters:
                    q.append(typed+letter)
        
        return list(q)