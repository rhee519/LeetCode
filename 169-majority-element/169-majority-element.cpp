class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num: nums) {
            m[num]++;
        }
        
        int maj = 0, cnt = 0;
        for(auto& e: m) {
            if(cnt < e.second) {
                maj = e.first;
                cnt = e.second;
            }
        }
        return maj;
    }
};