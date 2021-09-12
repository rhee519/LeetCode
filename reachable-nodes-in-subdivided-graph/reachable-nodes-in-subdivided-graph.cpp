class Compare {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    int between[3000][3000];
    bool visited[3000];
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<vector<pair<int, int>>> adj(n);
        int ret = 0;
        
        for(auto e: edges) {
            int from = e[0], to = e[1], cost = e[2]+1;
            adj[from].push_back({to, cost});
            adj[to].push_back({from, cost});
        }
        
        // init
        pq.push({0, 0});
        // BFS
        while(!pq.empty()) {
            pair<int, int> curr = pq.top(); pq.pop();
            int from = curr.first, dist = curr.second;
            if(visited[from]) continue;
            visited[from] = true; ret++;
            for(auto next: adj[from]) {
                int to = next.first, cost = next.second;
                // if(visited[to]) continue;
                if(dist + cost <= maxMoves) {
                    between[from][to] = cost - 1;
                    pq.push({to, dist + cost});
                } else {
                    between[from][to] = maxMoves - dist;
                }
            }
        }
        
        for(auto e: edges) {
            int from = e[0], to = e[1], cost = e[2]+1;
            ret += min(between[from][to] + between[to][from], cost-1);
        }
        
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << between[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        //         pq.push({1, 2});
//         pq.push({2, 1});
//         pq.push({1, 5});
//         pq.push({3, 7});
        
//         while(!pq.empty()) {
//             cout << pq.top().first << " " << pq.top().second << "\n";
//             pq.pop();
//         }
        
        return ret;
    }
};