class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long next = 1;
        int cnt = 0, i = 0, size = nums.size();
        // [1, next) is covered
        while(next <= n) {
            if(i < size && nums[i] <= next) {
                next += nums[i++];  // now we cover [1, next + nums[i]) (don't need to add/patch)
            } else {                // next <= nums[i]
                next = next<<1;     // best option is to add/patch next
                cnt++;              // now we cover [1, 2*next)
            }
        }
            
        return cnt;
    }
};