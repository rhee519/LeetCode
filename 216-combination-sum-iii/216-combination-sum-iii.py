class Solution:
    def combinationSum3(
        self,
        k: int,
        n: int,
        prefix: List[int] = [],
        total: int = 0
    ) -> List[List[int]]:
        # print("-----------------------------")
        start = 1 if len(prefix) == 0 else prefix[-1]+1
        # print(f"prefix: {prefix}, , total: {total}, start: {start}")
        
        if k == 1:
            if start <= n-total < 10:
                return [prefix+[n-total]]
            else:
                return []
        
        ret = []
        for i in range(start, 10):
            lcomb = prefix+[i]
            # print(f"lcomb: {lcomb}")
            combs = self.combinationSum3(
                k=k-1,
                n=n,
                prefix=lcomb,
                total=total+i
            )
            # print(f"combs: {combs}")
            for comb in combs:
                ret.append(comb)
        
        # print(f"ret: {ret}")
        # print("-----------------------------")
        return ret
            