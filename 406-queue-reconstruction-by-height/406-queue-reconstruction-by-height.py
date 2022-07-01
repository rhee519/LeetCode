class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        ans = [[10**9, 0] for _ in range(len(people))]
        people.sort(key=lambda x: (-x[0], -x[1]))
        # print(people)
        while people:
            h, k = people.pop()
            # print(f'h: {h}, k: {k}')
            pos = -1
            for i in range(len(ans)):
                if ans[i][0] >= h:
                    pos += 1
                if pos == k:
                    ans[i] = [h, k]
                    break
            # print(f'ans: {ans}')
        
        return ans