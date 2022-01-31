class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto& acc: accounts) {
            int sum = 0;
            for(int num: acc) {
                sum += num;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};