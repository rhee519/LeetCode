class Solution {
private:
    int up[500][500], down[500][500], left[500][500], right[500][500], grid[500][500];
    // grid[i][j] == 0 : plus sign
    //            == -1 : mine
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        for(auto mine: mines) {
            grid[mine[0]][mine[1]] = -1;
        }
        // dynamic programming for 4 directions
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // left -> right, up -> down
                if(i > 0) {
                    up[i][j] = grid[i-1][j] == 0? up[i-1][j]+1 : 0;
                }
                if(j > 0) {
                    left[i][j] = grid[i][j-1] == 0? left[i][j-1]+1 : 0;
                }
            }
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                // right -> left, down -> up
                if(i < n-1) {
                    down[i][j] = grid[i+1][j] == 0? down[i+1][j]+1 : 0;
                }
                if(j < n-1) {
                    right[i][j] = grid[i][j+1] == 0? right[i][j+1]+1 : 0;
                }
            }
        }
        
        // get max order
        int maxOrder = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == -1) continue;  // mine can't be the center of plus sign
                int order = min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])) + 1;
                maxOrder = maxOrder < order ? order : maxOrder;
            }
        }
        
        return maxOrder;
    }
};