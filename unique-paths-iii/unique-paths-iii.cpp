class Solution {
public:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    bool check(int m, int n, int i, int j) {
        return 0 <= i and i < m and 0 <= j and j < n;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j, int endR, int endC, int cnt, int space, int& ans) {
        int m = grid.size(), n = grid[0].size();
        cnt++;
        visit[i][j] = true;
        if(i == endR and j == endC) { // arrived at ending square
            if(cnt == space) ans++;
        } else {
            for(int d = 0; d < 4; d++) {
                int _i = i+dy[d], _j = j+dx[d]; // next pos
                if(check(m, n, _i, _j) and grid[_i][_j] != -1 and !visit[_i][_j])
                    dfs(grid, visit, _i, _j, endR, endC, cnt, space, ans);
            }
        }
        visit[i][j] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int startR, startC, endR, endC;
        int m = grid.size(), n = grid[0].size(), space = m*n;
        vector<vector<bool>> visit(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                switch(grid[i][j]) {
                    case -1: space--; break;
                    case 1: startR = i; startC = j; break;
                    case 2: endR = i; endC = j; break;
                }
            }
        }
        
        // dfs
        dfs(grid, visit, startR, startC, endR, endC, 0, space, ans);
        return ans;
    }
};