class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, mid = (left+right)/2;
        while(left < right) {
            int target = mid%2 ? mid-1 : mid+1;
            // if nums[mid] == nums[target], then unique num is in nums[mid+1:right]
            // else, unique num is in nums[left:mid]
            if(nums[mid] == nums[target]) {
                left = mid+1;
            } else {
                right = mid;
            }
            mid = (left+right)/2;
        }
        
        return nums[mid];
    }
};