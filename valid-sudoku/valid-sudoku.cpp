class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10], col[9][10], block[9][10];
        memset(row, 0, sizeof row);         // check row-direction
        memset(col, 0, sizeof col);         // check col-direction
        memset(block, 0, sizeof block);     // check each sub-box
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                row[i][num]++; col[j][num]++; block[(i/3)*3 + j/3][num]++;
                if(row[i][num] > 1 || col[j][num] > 1 || block[(i/3)*3 + j/3][num] > 1) {
                    cout << i << " " << j << "\n";
                    return false;
                }   
            }
        }
            
        return true;
    }
};