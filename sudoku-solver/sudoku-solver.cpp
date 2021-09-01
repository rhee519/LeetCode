class Solution {
private:
    int row[9][10], col[9][10], block[9][10];
public:
    bool check(vector<vector<char>>& board, int i, int j, int num) {
        // if there exists num in ith row || jth col || kth block
        // return false
        // else return true
        return !(row[i][num] || col[j][num] || block[(i/3)*3+j/3][num]);
    }
    
    bool dfs(vector<vector<char>>& board, int idx, int num) {
        // return if can fill num in board[idx] (ith row, jth col)
        while(idx < 9*9 && board[idx/9][idx%9] != '.') idx++;
        if(idx == 9*9) return true;
        int i = idx/9; int j = idx%9;
        if(!check(board, i, j, num)) return false;
        
        board[i][j] = num + '0';
        row[i][num]++; col[j][num]++; block[(i/3)*3+j/3][num]++;
        for(int n = 1; n <= 9; n++) {
            if(dfs(board, idx+1, n)) return true;
        }
        board[i][j] = '.';
        row[i][num]--; col[j][num]--; block[(i/3)*3+j/3][num]--;
        
        return false;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int n = 1; n <= 9; n++) {
            if(dfs(board, 0, n)) return true;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                row[i][num] = col[j][num] = block[(i/3)*3+j/3][num] = 1;
            }
        }
        
        if(!solve(board)) cout << "error\n";
    }
};