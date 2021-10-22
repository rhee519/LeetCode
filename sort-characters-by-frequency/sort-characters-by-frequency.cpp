bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        map<char, int> Map;
        for(char ch: s) {
            Map[ch]++;
        }
        vector<pair<char, int>> v(Map.begin(), Map.end());
        sort(v.begin(), v.end(), compare);
        for(auto p: v) {
            ans += string(p.second, p.first);
        }
        
        return ans;
    }
};