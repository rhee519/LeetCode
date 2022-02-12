class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> wordmap, visit;
        queue<pair<string, int>> q;
        
        // store wordList into map
        for(string word: wordList) {
            wordmap[word]++;
        }
        
        q.push({beginWord, 1});
        visit[beginWord]++;
        while(!q.empty()) {
            pair<string, int> curr = q.front(); q.pop();
            string curr_str = curr.first;
            int next_len = curr.second+1;
            for(int i = 0; i < curr_str.size(); i++) {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    string next_str = curr_str;
                    next_str[i] = ch;
                    if(wordmap.count(next_str) and !visit.count(next_str)) {
                        if(next_str == endWord) return next_len;
                        q.push({next_str, next_len});
                        visit[next_str]++;
                    }
                }
            }
        }
        
        // no valid transformation
        return 0;
    }
};