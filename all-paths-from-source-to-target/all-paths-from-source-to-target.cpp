class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        int n = graph.size();
        queue<vector<int>> q;
        q.push(vector<int>(1)); // q.push([0])
        while(!q.empty()) {
            vector<int> p = q.front(); q.pop();
            for(int next: graph[p.back()]) {
                vector<int> path = p;
                path.push_back(next);
                if(next == n-1) paths.push_back(path);
                else q.push(path);
            }
        }
        return paths;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return bfs(graph);
    }
};