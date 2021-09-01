class Solution {
public:
    int dp[2001];
    // dp[i] == minCut of string s[0:i]
    bool palindrome[2001][2001];
    // palindrome[i][j] == (s[i:j] is a palindrome)
    
    bool check(int start, int end) {
        if(start >= end) return true;
        return palindrome[start][end];
    }
    
    int minCut(string s) {
        int len = s.length();
        
        for(int end = 0; end < len; end++) {
            dp[end] = end;
            for(int start = 0; start <= end; start++) {
                if(s[start] == s[end] && check(start+1, end-1)) {
                    palindrome[start][end] = true;
                    if(start == 0) dp[end] = 0;
                    else if(dp[end] > dp[start-1] + 1) {
                        dp[end] = dp[start-1] + 1;
                    }
                }
            }
        }
        
        return dp[len-1];
    }
};