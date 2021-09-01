class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.length();
        
        // init
        int flip = 0;
        int cnt1s = 0;
        
        // dynamic programming
        for(auto ch : s) {
            if(ch == '0') {
                flip = min(cnt1s, flip + 1);
            } else { // s[i] == '1'
                cnt1s++;
            }
        }
        
        return flip;
    }
};