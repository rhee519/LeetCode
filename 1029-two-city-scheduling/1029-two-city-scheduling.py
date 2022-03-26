class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        gap = [(idx, cost[0]-cost[1]) for idx, cost in enumerate(costs)]
        gap.sort(key=lambda x: x[1])
        ans = 0
        for i in range(len(costs)//2):
            # gap[0][0], gap[1][0], ..., gap[n][0] goes to A
            ans += costs[gap[i][0]][0]
        for i in range(len(costs)//2, len(costs)):
            # gap[n+1][0], gap[n+2][0], ..., gap[2n][0] goes to B
            ans += costs[gap[i][0]][1]
        
        return ans
        