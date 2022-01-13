class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i]) continue;
            int j = i+1;
            while(j < n and nums[j] == 0) j++;
            if(j == n) return;
            swap(nums[i], nums[j]);
        }
    }
};