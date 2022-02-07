class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = {0, };
        for(char ch: s) {
            cnt[ch-'a']++;
        }
        for(char ch: t) {
            cnt[ch-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) return i+'a';
        }
        return ' ';
    }
};