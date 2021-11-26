class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = (left+right)/2;
        while(left < right) {
            if(nums[mid] == target) break;
            else if(nums[mid] > target) right = mid;
            else left = mid+1;
            mid = (left+right)/2;
        }
        return nums[mid] >= target ? mid : mid+1;
    }
};