class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 1; int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] < 0) continue;   // already visited
            int curr = i;
            int len = 0;
            while(nums[curr] >= 0) {
                int next = nums[curr]; nums[curr] = -1; curr = next;
                len++;
            }
            if(maxLen < len) maxLen = len;
        }
        
        return maxLen;
    }
};