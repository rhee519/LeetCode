class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, cnt(26);
        // unordered_map<char, int> cnt;
        int m = s.size(), n = p.size();
        if(m < n) return ans;
        
        for(int i = 0; i < n; i++) {
            cnt[s[i]-'a']++;
            cnt[p[i]-'a']--;
        }
        
        // sliding window
        for(int i = 0; i+n <= m; i++) {
            bool isAnagram = true;
            for(int diff: cnt) {
                if(diff) {
                    isAnagram = false;
                    break;
                }
            }
            if(isAnagram) ans.push_back(i);
            if(i+n < m) {
                cnt[s[i]-'a']--;
                cnt[s[i+n]-'a']++;
            }
        }
        return ans;
    }
};