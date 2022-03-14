class Solution:
    def simplifyPath(self, path: str) -> str:
        segments = []
        paths = path.split('/')
        for p in paths:
            if p == '' or p == '.':
                continue
            elif p == '..':
                if segments:
                    segments.pop()
                else:
                    continue
            else: # p == valid path segment
                segments.append(p)
        
        return '/' + '/'.join(segments)