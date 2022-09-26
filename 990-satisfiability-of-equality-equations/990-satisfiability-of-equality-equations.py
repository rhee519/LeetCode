class Solution:
    def find(self, parent: Dict, ch: str) -> str:
        if parent[ch] == ch:
            return ch
        parent[ch] = self.find(parent, parent[ch])
        return parent[ch]
    
    def union(self, parent: Dict, __ch1: str, __ch2: str):
        ch1, ch2 = self.find(parent, __ch1), self.find(parent, __ch2)
        parent[ch2] = ch1
    
    def equationsPossible(self, equations: List[str]) -> bool:
        parent = {}
        eqs, neqs = list(filter(lambda x: x[1:3] == "==", equations)), list(filter(lambda x: x[1:3] == "!=", equations))
        
        # union & find
        for eq in eqs:
            ch1, ch2 = eq[0], eq[-1]
            if ch1 not in parent:
                parent[ch1] = ch1
            if ch2 not in parent:
                parent[ch2] = ch2
            self.union(parent, ch1, ch2)
        
        # print('--------------------')
        # print(f"parent: {parent}")
        # print(f"neqs: {neqs}")
        
        # check inequality
        for neq in neqs:
            ch1 = self.find(parent, neq[0]) if neq[0] in parent else neq[0]
            ch2 = self.find(parent, neq[-1]) if neq[-1] in parent else neq[-1]
            if ch1 == ch2:
                return False
        
        return True
        