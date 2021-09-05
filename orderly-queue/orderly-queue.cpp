class Solution {
public:
    string orderlyQueue(string s, int k) {
        int cnt[26] = {0, };
        string ans = s;
        int len = s.length();
        if(k == 1) {
            for(int i = 0; i < len; i++) {
                string rotate = s.substr(i) + s.substr(0, i);
                if(ans > rotate) ans = rotate;
            }
        } else { // k >= 2
            for(char ch: s) {
                cnt[ch-'a']++;
            }
            ans = "";
            for(int i = 0; i < 26; i++) {
                ans += string(cnt[i], i+'a');
            }
        }
        
        return ans;
    }
};