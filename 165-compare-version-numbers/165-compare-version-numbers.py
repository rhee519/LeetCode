class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # split string
        ver1 = version1.split('.')
        ver2 = version2.split('.')
        # remove leading zero
        v1 = [s.lstrip('0') for s in ver1]
        v2 = [s.lstrip('0') for s in ver2]
        
        # 0-padding
        for i in range(len(v1)):
            if v1[i] == '': 
                v1[i] = '0'
        for i in range(len(v2)):
            if v2[i] == '':
                v2[i] = '0'
        
        # convert version string -> int
        for i in range(len(v1)):
            v1[i] = int(v1[i])
        for i in range(len(v2)):
            v2[i] = int(v2[i])
        
        # resize both lists to make comparison easy
        maxlen = max(len(v1), len(v2))
        for i in range(len(v1), maxlen):
            v1.append(0)
        for i in range(len(v2), maxlen):
            v2.append(0)
        
        # version compare
        for i in range(maxlen):
            if v1[i] < v2[i]:
                return -1
            elif v1[i] > v2[i]:
                return 1
        
        # same version
        return 0