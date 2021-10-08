class Solution {
public:
    bool visited[6][6];
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    bool canMakeWord(vector<vector<char>> board, string word) {
        int upper[26] = {0, }, lower[26] = {0, };
        int m = board.size(), n = board[0].size(), len = word.size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if('A' <= board[i][j] and board[i][j] <= 'Z') {
                    upper[board[i][j]-'A']++;
                } else { // lower case
                    lower[board[i][j]-'a']++;
                }
            }
        }
        for(int i = 0; i < len; i++) {
            if('A' <= word[i] and word[i] <= 'Z') {
                upper[word[i]-'A']--;
                if(upper[word[i]-'A'] < 0) return false;
            } else { // lower case
                lower[word[i]-'a']--;
                if(lower[word[i]-'a'] < 0) return false;
            }
        }
        return true;
    }
    
    bool boundCheck(int m, int n, int r, int c) {
        return (0 <= r and r < m) and (0 <= c and c < n);
    }
    
    bool bfs(vector<vector<char>> board, string word, int r, int c) {
        queue<pair<pair<int, int>, int>> q;
        int m = board.size(), n = board[0].size(), len = word.size();
        if(len == 1) return true;
        memset(visited, false, sizeof visited);
        q.push({{r, c}, 0});
        
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int currR = p.first.first, currC = p.first.second, currId = p.second;
            visited[currR][currC] = true;
            printf("(%d,%d) id: %d\n", currR, currC, currId);
            for(int i = 0; i < 4; i++) {
                int nextR = currR+dy[i], nextC = currC+dx[i];
                if(!boundCheck(m, n, nextR, nextC) || visited[nextR][nextC] || board[nextR][nextC] != word[currId+1])
                    continue;
                if(currId+1 == len-1) return true;
                q.push({{nextR, nextC}, currId+1});
                visited[nextR][nextC] = true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>> board, string word, int r, int c, int idx) {
        if(idx == word.size()-1) return true;
        int m = board.size(), n = board[0].size();
        visited[r][c] = true;
        for(int i = 0; i < 4; i++) {
            int nextR = r+dy[i], nextC = c+dx[i];
            if(boundCheck(m, n, nextR, nextC) and !visited[nextR][nextC] and board[nextR][nextC] == word[idx+1]) {
                if(dfs(board, word, nextR, nextC, idx+1)) return true;
            }
        }
        
        visited[r][c] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.size();
        if(!canMakeWord(board, word)) return false;
        vector<pair<int, int>> init;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) init.push_back({i, j});
            }
        }
        
        for(auto p: init) {
            // if(bfs(board, word, p.first, p.second)) return true;
            memset(visited, false, sizeof visited);
            if(dfs(board, word, p.first, p.second, 0)) return true;
        }
        
        return false;
    }
};