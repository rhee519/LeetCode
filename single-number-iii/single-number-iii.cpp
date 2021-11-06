class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> Map;
        for(int num: nums) {
            Map[num]++;
        }
        for(auto it = Map.begin(); it != Map.end(); it++) {
            if(it->second == 1) ans.push_back(it->first);
        }
        return ans;
    }
};