class Solution {
public:
    int rob(vector<int>& nums) {
        int steal = 0, pass = 0;
        // steal := max profit w/ stealing house today
        // pass := max profit w/ passing house today
        for(int num: nums) {
            int prev_steal = steal, prev_pass = pass;
            steal = max(prev_pass+num, prev_steal);
            pass = max(prev_steal, prev_pass);
        }
        return max(steal, pass);
    }
};