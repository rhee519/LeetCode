class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MODULO = int(10**9+7)
        result = 0
        for i in range(1, n+1):
            shift = floor(log2(i))+1
            # print(f"i: {i}, shift: {shift}")
            result <<= shift
            result += i
            result %= MODULO
        
        return result%MODULO