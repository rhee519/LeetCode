class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        ret = []
        for word in words:
            w_to_p = {}
            p_to_w = {}
            match = True
            for i in range(len(word)):
                if word[i] in w_to_p:
                    if w_to_p[word[i]] != pattern[i]:
                        match = False
                        break
                    continue
                if pattern[i] in p_to_w:
                    match = False
                    break
                w_to_p[word[i]] = pattern[i]
                p_to_w[pattern[i]] = word[i]
                    
            if match:
                ret.append(word)
        
        return ret