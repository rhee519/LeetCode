"""
example return value

s = "abc???g", stamp = "abcdefg"
return: True

s = "aa", stamp = "b"
return: False
"""
def compare(s: str, stamp: str) -> bool:
    len_stamp = len(stamp)
    if len(s) != len_stamp:
        return False
    if s == "?" * len_stamp:
        return False
    
    for i in range(len(s)):
        if s[i] == '?':
            continue
        if s[i] != stamp[i]:
            return False
    
    return True

class Solution:
    """
    stamp = "abca", target = "aabcaca"
    1. "aabcaca"
    2. "a????ca", ans = [1]
    3. "?????ca", ans = [0, 1]
    4. "???????", ans = [3, 0, 1]
    """
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        s = target
        ans = deque()

        len_stamp = len(stamp)
        STAMP_MARK = "?" * len_stamp
        finished = False
        while not finished:
            # print(s)
            finished = True
            for i in range(len(s)-len_stamp+1):
                if compare(s[i:i+len_stamp], stamp):
                    finished = False
                    ans.appendleft(i)
                    s = s[:i] + STAMP_MARK + s[i+len_stamp:]
        
        # check result
        # print('--------------')
        for ch in s:
            if ch != '?':
                return []
        return list(ans)
        