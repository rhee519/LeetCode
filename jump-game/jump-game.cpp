class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        
        for(int i = 0; i <= reachable; i++) {
            reachable = max(reachable, i+nums[i]);
            if(reachable >= n-1) break;
        }
        
        return reachable >= n-1;
    }
};