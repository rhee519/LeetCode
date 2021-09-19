class Solution {
public:
    unsigned long int dp[1000][1000];
    // dp[i][j] == # matches of t[0:j] from s[0:i]
    //          == numDistinct(s[0:i], t[0:j])
    // notice: j <= i, else dp[i][j] = 0
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        if(slen < tlen) return 0;
        
        // init
        dp[0][0] = s[0] == t[0]? 1 : 0;
        for(int i = 1; i < slen; i++) {
            dp[i][0] = s[i] == t[0]? dp[i-1][0]+1 : dp[i-1][0];
        }
        
        // dynamic programming
        for(int i = 1; i < slen; i++) {
            for(int j = 1; j <= i && j < tlen; j++) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    // dp[i][j] %= (long int)INT_MAX+1;
                    // s[0:i-1]과 t[0:j-1]이 match하고 s[i] == t[j] => dp[i-1][j-1]
                    // s[0:i-1]과 t[0:j]가 match                   => dp[i-1][j]
                } else {
                    // s[0:i-1]과 t[0:j]가 match
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // for(int i = 0; i < slen; i++) {
        //     for(int j = 0; j < tlen; j++)  {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        return dp[slen-1][tlen-1];
    }
};