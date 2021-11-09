class Solution {
public:
    int getMask(string& str) {
        int mask = 0, flag;
        for(char ch: str) {
            flag = 1 << (ch-'a');
            mask |= flag;
        }
        return mask;
    }
    
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        int m = words.size(), n = puzzles.size();
        vector<int> ans(n);
        for(string word: words) {
            int mask = getMask(word);
            freq[mask]++;
        }
        
        for(int i = 0; i < n; i++) {
            int mask = getMask(puzzles[i]), submask = mask, first = 1<<(puzzles[i][0]-'a');
            while(submask) {
                if(freq.count(submask) and submask&first)
                    ans[i] += freq[submask];
                submask = (submask-1)&mask;
            }
        }
        
        return ans;
    }
};