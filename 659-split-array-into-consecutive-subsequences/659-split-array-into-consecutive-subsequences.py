class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        olist = {}
        # olist[end][start] == # (start, start+1, ..., end-1, end)
        
        for num in nums:
            if num not in olist:
                olist[num] = {}
            # print(olist)
            if num-1 not in olist:
                if num not in olist[num]:
                    olist[num][num] = 1
                else:
                    olist[num][num] += 1
                continue
            startList = olist[num-1].keys()
            if len(startList) == 0:
                if num not in olist[num]:
                    olist[num][num] = 1
                else:
                    olist[num][num] += 1
                continue
            
            # (start, ..., num-1) + (num)
            start = max(startList) # shortest subsequence
            olist[num-1][start] -= 1
            if olist[num-1][start] == 0:
                del olist[num-1][start]
            if start not in olist[num]:
                olist[num][start] = 0
            olist[num][start] += 1
            
        # print(olist)
        # print('---------')
        for num in olist:
            for start in olist[num]:
                if num-start < 2:
                    return False
        
        return True