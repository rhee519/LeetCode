class Solution:
    def maxEnvelopes(self, en: List[List[int]]) -> int:
        en.sort(key = lambda x: (x[0], -x[1]))
        nums, elist = [j for _, j in en], []
        
        for current in nums:
            idx = bisect.bisect_left(elist, current)
            elist[idx:idx+1] = [current]
            # print(f'current: {current}, idx: {idx}')
            # print(elist)
        return len(elist)