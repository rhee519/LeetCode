class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        INF = 100000
        length = len(tops)
        ans = INF
        container = [None] + [set() for _ in range(6)]
        top_cnt, bottom_cnt = [0] * 7, [0] * 7
        
        for i in range(length):
            container[tops[i]].add(i)
            container[bottoms[i]].add(i)
            top_cnt[tops[i]] += 1
            bottom_cnt[bottoms[i]] += 1
        
        for i in range(1, 7):
            if len(container[i]) < length:
                continue
            swap = length - max(top_cnt[i], bottom_cnt[i])
            ans = min(ans, swap)
        
        # print(container[1:])
        # print(top_cnt, bottom_cnt)
        
        return -1 if ans == INF else ans