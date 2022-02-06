class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, dup = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] == nums[i]) dup++;
            else dup = 1;
            if(dup < 3) nums[idx++] = nums[i];
        }
        return idx;
    }
};