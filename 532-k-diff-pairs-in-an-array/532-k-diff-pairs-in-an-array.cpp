class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int cnt = 0;
        for(int num: nums) {
            m[num]++;
        }
        
        if(k == 0) {
            for(auto& e: m) {
                int key = e.first;
                if(m[key] > 1) cnt++;
            }
        } else {
            for(auto& e: m) {
                int key = e.first, tar = key-k;
                if(m.count(tar)) cnt++;
            }
        }
        
        return cnt;
    }
};