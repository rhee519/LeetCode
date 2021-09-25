class Info {
public:
    int y, x, r, dist;
    Info(int y = 0, int x = 0, int r = 0, int dist = 0) {
        this->y = y; this->x = x; this->r = r; this->dist = dist;
    }
};

class Solution {
public:
    bool isInBound(int y, int x, int m, int n) {
        return (0 <= y and y < m) and (0 <= x and x < n);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> remain(m, vector<int>(n, 0));
        queue<Info> q;
        int diff[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        
        // init BFS
        q.push(Info(0, 0, k, 0));
        visited[0][0] = true; remain[0][0] = k;
        
        // BFS
        while(!q.empty()) {
            Info curr = q.front(); q.pop();
            int y = curr.y, x = curr.x, r = curr.r, dist = curr.dist;
            if(y == m-1 and x == n-1) return dist;
            for(int i = 0; i < 4; i++) {
                int nextY = y+diff[i][0], nextX = x+diff[i][1];
                if(!isInBound(nextY, nextX, m, n)) continue;
                if(visited[nextY][nextX] && remain[nextY][nextX] >= r) continue;
                if(grid[nextY][nextX] == 0) { // empty
                    q.push(Info(nextY, nextX, r, dist+1));
                    visited[nextY][nextX] = true; remain[nextY][nextX] = r;
                } else { //obstacle
                    if(r > 0) q.push(Info(nextY, nextX, r-1, dist+1));           
                    visited[nextY][nextX] = true; remain[nextY][nextX] = r-1;
                }
            }
        }
        
        // no path
        return -1;
    }
};