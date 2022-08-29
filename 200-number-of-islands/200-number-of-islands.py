dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def checkBound(y: int, x: int, m: int, n: int) -> bool:
    return 0 <= y < m and 0 <= x < n

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        LAND = '1'
        WATER = '0'
        numIsland = 0
        m, n = len(grid), len(grid[0])
        # print(m, n)
        for i in range(m):
            for j in range(n):
                # print(f'i: {i}, j: {j}')
                if grid[i][j] == WATER:
                    continue
                q = deque([(i, j)])
                grid[i][j] = WATER
                while q:
                    y, x = q.popleft()
                    for d in range(4):
                        ny, nx = y+dy[d], x+dx[d]
                        if checkBound(ny, nx, m, n) and grid[ny][nx] == LAND:
                            q.append((ny, nx))
                            grid[ny][nx] = WATER
                numIsland += 1
                            
        return numIsland