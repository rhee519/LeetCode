class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> idx;
        int cnt = 0, sum = 0;
        
        idx[0] = 1;
        for(int num: nums) {
            sum += num;
            if(idx.count(sum-k)) {
                cnt += idx[sum-k];
            }
            idx[sum]++;
        }
        return cnt;
    }
};