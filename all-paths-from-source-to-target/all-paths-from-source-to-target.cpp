class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths) {
        int n = graph.size();
        for(int next: graph[path.back()]) {
            vector<int> next_path = path;
            next_path.push_back(next);
            if(next == n-1) paths.push_back(next_path);
            else dfs(graph, next_path, paths);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path(1); // [0]
        dfs(graph, path, ans);
        return ans;
    }
};