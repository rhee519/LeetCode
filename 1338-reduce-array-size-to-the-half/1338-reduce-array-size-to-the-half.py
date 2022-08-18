class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        numset = set()
        removed = 0
        # print(cnt)
        for num, count in cnt.most_common():
            # print(num)
            numset.add(num)
            removed += count
            if removed >= len(arr)/2.0:
                break
        
        return len(numset)