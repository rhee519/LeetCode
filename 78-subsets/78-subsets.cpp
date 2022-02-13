class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for(auto num: nums) {
            int len = ans.size();
            for(int i = 0; i < len; i++) {
                auto subset = ans[i];
                subset.push_back(num);
                ans.push_back(subset);
            }
        }
        return ans;
    }
};