class Solution {
public:
    int maxPower(string s) {
        int ans = 0, seq = 0;
        char prev = s[0];
        for(char ch: s) {
            if(ch == prev) seq++;
            else seq = 1;
            ans = max(ans, seq);
            prev = ch;
        }
        return ans;
    }
};