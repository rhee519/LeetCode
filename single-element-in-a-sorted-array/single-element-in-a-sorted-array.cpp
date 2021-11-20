class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int prev = 0, curr = 0, ans;
        int n = nums.size();
        while(true) {
            while(curr < n and nums[prev] == nums[curr]) curr++;
            if(curr >= n) break;
            if(prev+1 == curr) return nums[prev];
            prev = curr;
        }
        
        return nums[n-1];
    }
};