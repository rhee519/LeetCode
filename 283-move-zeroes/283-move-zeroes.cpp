class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            nums[idx++] = nums[i];
        }
        for(int i = idx; i < n; i++) {
            nums[i] = 0;
        }
    }
};