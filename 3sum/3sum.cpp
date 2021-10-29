class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> Map;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            Map[nums[i]] = i;
        }
        
        for(int i = 0; i < n; i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++) {
                if(j > i+1 and nums[j] == nums[j-1]) continue;
                int target = -(nums[i]+nums[j]);
                if(Map.count(target) and Map[target] > j) {
                    vector<int> trip(3);
                    trip[0] = nums[i]; trip[1] = nums[j]; trip[2] = target;
                    ans.push_back(trip);
                }
            }
        }
        
        return ans;
    }
};