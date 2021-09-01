class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // if(!matrix.size()) return;      // matrix is empty
        int row = matrix.size();
        int col = matrix[0].size();
        bool reset0thRow = matrix[0][0] == 0;
        
        // zero check
        // index-based loop
        for(int j = 0; j < col; j++) {
            if(matrix[0][j] == 0) {
                reset0thRow = true; break;
            }
        }
        
        for(int i = 1; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // zero set
        // matrix[0:row-1][0], matrix[0][0:col-1] == flags
        // update 0th row at the last
        // row (1 ~ row-1)
        for(int i = 1; i < row; i++) {
            if(matrix[i][0] == 0) {
                memset(&matrix[i][0], 0, col * sizeof matrix[i][0]);
            }
        }
        // col
        for(int j = 0; j < col; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // row (0)
        if(reset0thRow) {
            memset(&matrix[0][0], 0, col * sizeof matrix[0][0]);
        }
    }
};