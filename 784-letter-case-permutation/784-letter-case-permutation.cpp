class Solution {
public:
    void dfs(vector<string>& ans, string& s, int idx) {
        if(idx == s.size()) {
            ans.push_back(s);
            return;
        }
        
        if('a' <= s[idx] and s[idx] <= 'z') {
            // lower
            dfs(ans, s, idx+1);
            // upper
            s[idx] += 'A'-'a';
            dfs(ans, s, idx+1);
        } else if('A' <= s[idx] and s[idx] <= 'Z') {
            // upper
            dfs(ans, s, idx+1);
            s[idx] += 'a'-'A';
            dfs(ans, s, idx+1);
        } else {
            dfs(ans, s, idx+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(ans, s, 0);
        return ans;
    }
};