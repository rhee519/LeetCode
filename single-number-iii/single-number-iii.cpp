class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> Map;
        for(int num: nums) {
            if(Map.count(num)) Map.erase(num);
            else Map[num]++;
        }
        for(auto it: Map) {
            ans.push_back(it.first);
        }
        return ans;
    }
};