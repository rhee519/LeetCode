class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int max(int a, int b, int c) {
        if(a > b) {
            return a > c ? a : c;
        } else {
            return b > c ? b : c;
        }
    }
    int abs(int a) {
        return a > 0 ? a : -a;
    }
    
    bool stoneGame(vector<int>& piles) {
        int dp[501][501];
        // dp[i][j] == max(alex.score - lee.score) on piles[i:j]
        int size = piles.size();
        int i;
        // init
        for(i = 0; i < size-1; i++) {
            dp[i][i+1] = abs(piles[i] - piles[i+1]);
        }
        
        // dynamic programming
        i = 0;
        for(int d=3; d<size; d++) {
            for(i=0; i+d<size; i++) {
            dp[i][i+d] = max(piles[i]-piles[i+1]+dp[i+2][i+d], abs(piles[i]-piles[i+d])+dp[i+1][i+d-1], piles[i+d]-piles[i+d-1]+dp[i][i+d-2]);
            }
        }
        
        return dp[0][size-1];
    }
};