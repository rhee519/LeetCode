class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int ridx = lower_bound(nums.rbegin(), nums.rend(), nums[0]) - nums.rbegin();
        return nums[(size-ridx)%size];
    }
};