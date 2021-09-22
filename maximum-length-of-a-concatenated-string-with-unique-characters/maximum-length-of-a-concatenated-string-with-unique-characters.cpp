class Solution {
public:
    bool check(string str) {
        if(str.size() > 26) return false;
        int cnt[26] = {0, };
        for(char ch: str) {
            cnt[ch-'a']++;
            if(cnt[ch-'a'] > 1) return false;
        }
        return true;
    }
    
    int maxLength(vector<string>& arr) {
        int maxLen = 0, n = arr.size(), n2 = 1<<n;
        vector<int> dp(n2+1, 0);
        for(int i = 1; i < dp.size()-1; i++) {
            int idx = i;
            string str = "";
            while(idx) {
                int log_2 = log2(idx);
                str = arr[log_2] + str;
                idx -= (int)pow(2, log_2);
            }
            if(check(str) && maxLen < str.size()) maxLen = str.size();
        }
        
        return maxLen;
    }
};