class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.size();
        int memo = 0;
        // memo == length of longest substr with last letter s[i]
        unordered_map<char, int> cnt;
        for(int i = 0; i < n; i++) {
            int pos = cnt.count(s[i])? cnt[s[i]] : -1;
            memo = min(memo+1, i-pos);
            cnt[s[i]] = i;
            ans = max(ans, memo);
        }
        return ans;
    }
};