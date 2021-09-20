class Solution {
public:
    int board[3][3]; // A: 1, B: -1
    
    bool check(int r, int c, int player) {
        // player == 1: A, -1: B
        bool result = true;
        
        // check r-th row
        for(int i = 0; i < 3; i++) {
            if(board[r][i] != player) {
                result = false; break;
            }
        }
        if(result) return true;
        
        // check c-th column
        result = true;
        for(int i = 0; i < 3; i++) {
            if(board[i][c] != player) {
                result = false; break;
            }
        }
        if(result) return true;
        
        // check diagonal
        if(r == c) {   // (0,0), (1,1), (2,2)
            result = board[0][0] == player and board[1][1] == player and board[2][2] == player;
            if(result) return true;
        }
        if(r+c == 2) { // (0,2), (1,1), (2,0)
            result = board[0][2] == player and board[1][1] == player and board[2][0] == player;
            if(result) return true;
        }
        
        return false;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        if(n < 5) return "Pending";
        for(int i = 0; i < n; i++) {
            int r = moves[i][0], c = moves[i][1];
            if(i%2 == 0) { // A's turn
                board[r][c] = 1;
                if(check(r, c, 1)) return "A";
            } else {       // B's turn
                board[r][c] = -1;
                if(check(r, c, -1)) return "B";
            }
        }
        if(n == 9) return "Draw";
        return "Pending";
    }
};