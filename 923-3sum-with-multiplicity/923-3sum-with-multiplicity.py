class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        modulo = 10**9+7
        c = collections.Counter(arr)
        ans = 0
        
        for i, j in itertools.combinations_with_replacement(c, 2):
            i, j = min(i, j), max(i, j)
            k = target-(i+j)
            if k not in c or k < i or k < j:
                continue
            
            cnt = 1
            if i == j == k:
                cnt *= c[i] * (c[i]-1) * (c[i]-2) // 6
            elif i == j != k:
                cnt *= c[i] * (c[i]-1) * c[k] // 2
            elif i != j == k:
                cnt *= c[i] * c[j] * (c[j]-1) // 2
            else:
                cnt *= c[i] * c[j] * c[k]
            ans += cnt
            ans %= modulo
        return ans%modulo
        