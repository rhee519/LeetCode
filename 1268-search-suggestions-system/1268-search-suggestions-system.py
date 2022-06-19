def prefixCheck(target: str, prefix: str) -> bool:
    return target[0:len(prefix)] == prefix

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        wordSet = set(products)
        wordList = list(wordSet)
        wordList.sort()
        # print(wordList)
        
        ret = []
        prefix = ""
        for ch in searchWord:
            result = []
            prefix += ch
            # print(f'prefix: {prefix}')
            idx = bisect_left(wordList, prefix)
            # print(f'idx: {idx}')
            for i in range(idx, idx+3):
                if i >= len(wordList):
                    break
                if prefixCheck(wordList[i], prefix) is False:
                    break
                result.append(wordList[i])
            ret.append(result)
            
        return ret