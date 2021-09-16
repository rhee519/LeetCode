class Solution {
public:
    int visited[11][11];
    bool check(int i, int j, int rSize, int cSize, int direction) {
        switch(direction) {
            case 0: // right
                return j < cSize-1 && !visited[i][j+1];
            case 1: // down
                return i < rSize-1 && !visited[i+1][j];
            case 2: // left
                return j > 0 && !visited[i][j-1];
            case 3: // up
                return i > 0 && !visited[i-1][j];
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans(row * col);
        int direction = 0, cnt = 0;
        // 0: right, 1: down, 2: left, 3: up
        int i = 0, j = 0;
        while(cnt < row * col) {
            ans[cnt++] = matrix[i][j];
            visited[i][j] = true;
            direction %= 4;
            bool canMove = check(i, j, row, col, direction);
            switch(direction) {
                case 0: // right
                    if(canMove) {
                        j++;
                    } else {
                        i++; direction++;
                    } break;
                case 1: // down
                    if(canMove) {
                        i++;
                    } else {
                        j--; direction++;
                    } break;
                case 2: // left
                    if(canMove) {
                        j--;
                    } else {
                        i--; direction++;
                    } break;
                case 3: // up
                    if(canMove) {
                        i--;
                    } else {
                        j++; direction++;
                    } break;
            }
        }
        
        return ans;
    }
};