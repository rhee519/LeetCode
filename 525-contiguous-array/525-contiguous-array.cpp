class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, gap = 0;
        unordered_map<int, int> idx;
        idx[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) gap++;
            else gap--;
            
            if(!idx.count(gap)) idx[gap] = i;
            int len = i-idx[gap];
            ans = max(ans, len);
        }
        return ans;
    }
};