class Solution {
public:
    bool dfs(vector<int> nums, vector<int> v, int idx, int target) {
        if(idx == nums.size()) {
            for(int t: v) {
                if(t != target) return false;
            }
            return true;
        }
        // v.size() == k
        for(int i = 0; i < v.size(); i++) {
            vector<int> temp = v;
            temp[i] += nums[idx];
            if(temp[i] > target) continue;
            else if(temp[i] == nums[idx]) {
                // temp[i+1] ~ temp[k-1] == 0
                // nums[idx] is fixed in temp[i]
                return dfs(nums, temp, idx+1, target);
            }
            if(dfs(nums, temp, idx+1, target)) return true;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }

        if(sum%k) return false; // can't divide
        int target = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] > target) return false;
        
        vector<int> v(k);
        return dfs(nums, v, 0, sum/k);
    }
};