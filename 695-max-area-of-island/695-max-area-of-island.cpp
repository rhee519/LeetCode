class Solution {
public:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    bool check(int m, int n, int i, int j) {
        return 0 <= i and i < m and 0 <= j and j < n;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& cnt) {
        if(grid[i][j] == 0) return;
        int m = grid.size(), n = grid[0].size();
        grid[i][j] = 0;
        cnt++;
        for(int dir = 0; dir < 4; dir++) {
            int i_next = i+dy[dir], j_next = j+dx[dir];
            if(check(m, n, i_next, j_next)) {
                dfs(grid, i_next, j_next, cnt);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cnt = 0;
                dfs(grid, i, j, cnt);
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};