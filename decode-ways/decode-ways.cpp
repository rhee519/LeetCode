class Solution {
public:
    bool isChar(char front, char rear) {
        if(front == '0') return false;
        int num = (front - '0') * 10 + (rear - '0');
        return 1 <= num && num <= 26;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        if(n == 1) {
            if(s[0] == '0') return 0;
            else return 1;
        }
        int dp[n];
        memset(dp, 0, sizeof dp);
        
        // check first 2-digits
        dp[0] = dp[1] = 1;
        if(isChar(s[0], s[1])) {
            if(s[1] != '0') dp[1]++;
        } else {
            if(s[0] == '0' || s[1] == '0') return 0;
        }
        
        // dp
        for(int i = 2; i < n; i++) {
            if(isChar(s[i-1], s[i])) {
                if(s[i] == '0') dp[i] = dp[i-2];
                else            dp[i] = dp[i-2] + dp[i-1];
            } else {
                if(s[i] == '0') return 0;
                else            dp[i] = dp[i-1];
            }
        }
        
        return dp[n-1];
    }
};