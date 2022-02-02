class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> cnt;
        int m = s.size(), n = p.size();
        if(m < n) return ans;
        
        for(int i = 0; i < n; i++) {
            cnt[s[i]]++;
            cnt[p[i]]--;
        }
        
        // sliding window
        for(int i = 0; i+n <= m; i++) {
            bool isAnagram = true;
            for(auto& e: cnt) {
                if(e.second) {
                    isAnagram = false;
                    break;
                }
            }
            if(isAnagram) ans.push_back(i);
            if(i+n < m) {
                cnt[s[i]]--;
                cnt[s[i+n]]++;
            }
        }
        return ans;
    }
};