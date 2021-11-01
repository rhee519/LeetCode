class Solution {
public:
    bool visit[200][200];
    bool check(int m, int n, int i, int j) {
        return 0 <= i and i < m and 0 <= j and j < n;
    }
    bool boundary(int m, int n, int i, int j) {
        return i == 0 or i == m-1 or j == 0 or j == n-1;
    }
    void dfs(vector<vector<char>>& board, vector<pair<int, int>>& pos, int i, int j, bool& flip) {
        int m = board.size(), n = board[0].size();
        visit[i][j] = true;
        pos.push_back({i, j});
        if(boundary(m, n, i, j)) flip = false;
        if(check(m, n, i-1, j) and board[i-1][j] == 'O' and !visit[i-1][j]) dfs(board, pos, i-1, j, flip);
        if(check(m, n, i+1, j) and board[i+1][j] == 'O' and !visit[i+1][j]) dfs(board, pos, i+1, j, flip);
        if(check(m, n, i, j-1) and board[i][j-1] == 'O' and !visit[i][j-1]) dfs(board, pos, i, j-1, flip);
        if(check(m, n, i, j+1) and board[i][j+1] == 'O' and !visit[i][j+1]) dfs(board, pos, i, j+1, flip);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X' or visit[i][j]) continue;
                vector<pair<int, int>> pos;
                bool flip = true;
                dfs(board, pos, i, j, flip);
                if(flip) {
                    for(auto p: pos) {
                        board[p.first][p.second] = 'X';
                    }
                }
            }
        }
    }
};