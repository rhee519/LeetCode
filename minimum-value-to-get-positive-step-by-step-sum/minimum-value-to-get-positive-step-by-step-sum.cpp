class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ret = INT_MAX, sum = 0;
        for(int num: nums) {
            sum += num;
            if(ret > sum) ret = sum;
        }
        return max(-ret+1, 1);
    }
};