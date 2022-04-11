class Solution:
    def calPoints(self, ops: List[str]) -> int:
        scores = []
        for op in ops:
            if op.isdigit() or (op.startswith('-') and op[1:].isdigit()):
                scores.append(int(op))
            elif op == 'C':
                scores.pop()
            elif op == 'D':
                scores.append(scores[-1]*2)
            elif op == '+':
                scores.append(scores[-2]+scores[-1])
        
        return sum(scores)