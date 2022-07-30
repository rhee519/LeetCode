class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        ret = []
        lcnt = Counter()
        
        for word in words2:
            cnt = Counter(word)
            for ch in cnt:
                if ch not in lcnt:
                    lcnt[ch] = cnt[ch]
                else:
                    lcnt[ch] = max(lcnt[ch], cnt[ch])
        
        for word in words1:
            cnt = Counter(word)
            is_universal = True
            for ch in lcnt:
                if ch not in cnt or cnt[ch] < lcnt[ch]:
                    is_universal = False
                    break
            if is_universal:
                ret.append(word)
        
        return ret