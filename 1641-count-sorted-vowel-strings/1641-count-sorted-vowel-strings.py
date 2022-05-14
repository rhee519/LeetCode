class Solution:
    def countVowelStrings(self, n: int) -> int:
        # return # solutions of equation
        # x1 + x2 + x3 + x4 + x5 = n
        # x1, ..., x5 >= 0
        # -> combination allowing repetition
        # 5Hn == (5+n-1)Cn
        return comb(5+n-1, n)
        