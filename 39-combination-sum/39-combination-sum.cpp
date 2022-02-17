class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int> combination, int target, int idx) {
        if(target == 0) {
            ans.push_back(combination);
            return;
        } else if(target < 0 or idx == candidates.size())
            return;
        
        // exclude candidates[idx]
        dfs(ans, candidates, combination, target, idx+1);
        // include candidates[idx]
        combination.push_back(candidates[idx]);
        dfs(ans, candidates, combination, target-candidates[idx], idx);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        dfs(ans, candidates, combination, target, 0);
        return ans;
    }
};