class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& comb, int n, int k, int start) {
        if(comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        for(int i = start; i <= n; i++) {
            // include i
            comb.push_back(i);
            dfs(ans, comb, n, k, i+1);
            // exclude i
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(ans, comb, n, k, 1);
        return ans;
    }
};