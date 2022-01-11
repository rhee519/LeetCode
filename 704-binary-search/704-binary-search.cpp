class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = (left+right)/2;
        while(left < right) {
            if(nums[mid] < target) {
                left = mid+1;
            } else { // nums[mid] >= target
                right = mid;
            }
            mid = (left+right)/2;
        }
        return nums[mid] == target? mid : -1;
    }
};