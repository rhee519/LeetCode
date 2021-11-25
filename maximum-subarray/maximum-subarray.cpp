class Solution {
public:
    int dnc(vector<int>& nums, int left, int right) {
        if(left > right) return INT_MIN;
        if(left == right) return nums[left];
        int mid = (left+right)/2;
        int max_left = dnc(nums, left, mid);
        int max_right = dnc(nums, mid+1, right);
        int part = 0, max_mid_left = 0, max_mid_right = 0;
        for(int i = mid-1; i >= left; i--) {
            part += nums[i]; max_mid_left = max(max_mid_left, part);
        }
        part = 0;
        for(int i = mid+1; i <= right; i++) {
            part += nums[i]; max_mid_right = max(max_mid_right, part);
        }
        int max_mid = nums[mid] + max_mid_left + max_mid_right;
        
        return max(max(max_left, max_right), max_mid);
    }
    int maxSubArray(vector<int>& nums) {
        return dnc(nums, 0, nums.size()-1);
    }
};