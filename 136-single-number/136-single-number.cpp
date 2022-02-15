class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit = 0;
        for(int num: nums) {
            bit ^= num;
        }
        return bit;
    }
};