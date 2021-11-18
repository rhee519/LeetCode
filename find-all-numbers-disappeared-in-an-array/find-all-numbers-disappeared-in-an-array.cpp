class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int num: nums) {
            int idx = abs(num)-1;
            if(nums[idx] > 0) nums[idx] *= -1;
        }        
        for(int i = 0; i < n; i++) {
            if(nums[i]-1 >= 0) ans.push_back(i+1);
        }
        return ans;
    }
};