class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<vector<int>>> m;
        vector<vector<int>> ans;
        for(auto& point: points) {
            int dist = point[0]*point[0] + point[1]*point[1];
            m[dist].push_back(point);
        }
        for(auto& p: m) {
            for(auto& point: p.second) {
                ans.push_back(point);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};