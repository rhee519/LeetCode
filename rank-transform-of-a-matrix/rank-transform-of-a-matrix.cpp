class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void union_(int x, int y) {
        x = find(x); y = find(y);
        parent[y] = x;
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();
        map<int, vector<pair<int, int>>> myMap;
        
        vector<vector<int>> rank(rSize, vector<int>(cSize));
        vector<int> Max(rSize + cSize, 0);
        vector<int> rMax(rSize, 0);
        vector<int> cMax(cSize, 0);
        parent.reserve(rSize + cSize);
        
        // construct map
        for(int i = 0; i < rSize; i++) {
            for(int j = 0; j < cSize; j++) {
                myMap[matrix[i][j]].push_back({i, j});
            }
        }
        
        // ranking
        for(auto iter : myMap) {
            for(auto it : iter.second) {
                // here, we process coords with same key
                int r = it.first; int c = it.second;
                parent[r] = r;                  // DSU of rth row
                Max[r] = rMax[r];               // Max rank of rth row
                parent[c + rSize] = c + rSize;  // DSU of cth col
                Max[c + rSize] = cMax[c];       // Max rank of cth col
            }
            for(auto it : iter.second) {
                // union coords in the same row
                // or in the same col
                int r = find(it.first); int c = find(it.second + rSize);
                if(r != c) {        // rth row & cth col should have same max rank
                    union_(r, c);   // root[c] = r;
                    Max[r] = max(Max[r], Max[c]);
                }
            }
            for(auto it : iter.second) {
                // confirm rank
                int r = it.first; int c = it.second;
                int R = Max[find(r)] + 1;    // ... or Max[find(c + rSize)] + 1
                rank[r][c] = rMax[r] = cMax[c] = R;
            }
        }
        
        return rank;
    }
};