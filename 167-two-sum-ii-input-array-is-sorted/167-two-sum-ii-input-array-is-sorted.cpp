class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == target) break;
            else if(sum < target) {
                left++;
            } else { // sum > target
                right--;
            }
        }
        if(nums[left]+nums[right] == target) {
            ans.push_back(left+1);
            ans.push_back(right+1);
        }
        return ans;
    }
};