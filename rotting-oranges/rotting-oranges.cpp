class Info {
public:
    int y, x, time;
    Info(int y, int x, int time) {
        this->y = y; this->x = x; this->time = time;
    }
};

class Solution {
public:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    bool check(int m, int n, int y, int x) {
        return 0 <= y and y < m and 0 <= x and x < n;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<Info> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) {
                    q.push(Info(i, j, 0));
                }
            }
        }
        if(fresh == 0) return 0;
        
        // bfs
        while(!q.empty()) {
            Info curr = q.front(); q.pop();
            int y = curr.y, x = curr.x, time = curr.time;
            for(int i = 0; i < 4; i++) {
                int next_y = y+dy[i], next_x = x+dx[i];
                if(!check(m, n, next_y, next_x) or grid[next_y][next_x] != 1) 
                    continue;
                grid[next_y][next_x] = 2; fresh--;
                if(fresh == 0) return time+1;
                q.push(Info(next_y, next_x, time+1));
            }
        }
        
        return -1;
    }
};