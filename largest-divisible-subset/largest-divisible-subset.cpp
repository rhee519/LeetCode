class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& subset, vector<pair<int, int>>& parent, int key) {
        if(key == -1) return;
        dfs(nums, subset, parent, parent[key].first);
        subset.push_back(nums[key]);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        vector<pair<int, int>> parent(n);
        sort(nums.begin(), nums.end());
        parent[0] = pair(-1, 1);
        int longestKey = 0, longestLen = 1;
        
        for(int i = 1; i < n; i++) {
            bool found = false;
            pair<int, int> p = {-1, 1};
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j]) continue;
                if(p.second < parent[j].second+1) {
                    p.first = j; p.second = parent[j].second+1;
                }
            }
            parent[i] = p;
            if(longestLen < p.second) {
                longestKey = i; longestLen = p.second;
            }
        }
        
        dfs(nums, subset, parent, longestKey);
        // cout << nums[longestKey] << " " << longestLen << "\n";
        return subset;
    }
};