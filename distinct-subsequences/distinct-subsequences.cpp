class Solution {
public:
    unsigned long long int dp[1001][1001];
    // dp[i][j] == # matches of t[0:j-1] from s[0:i-1]
    //          == numDistinct(s[0:i-1], t[0:j-1])
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        if(slen < tlen) return 0;
        
        // init
        for(int i = 0; i < slen; i++) dp[i][0] = 1;
        // for(int j = 0; j < tlen; j++) dp[0][j] = 0;
        
        // dynamic programming
        for(int i = 1; i <= slen; i++) {
            for(int j = 1; j <= tlen; j++) {
                if(i < j) break;
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[slen][tlen];
    }
};