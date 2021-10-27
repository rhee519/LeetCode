class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0,};
        int i = 0, n = nums.size();
        for(int num: nums) {
            cnt[num]++;
        }
        for(int num = 0; num <= 2; num++) {
            while(cnt[num]--) nums[i++] = num;
        }
    }
};