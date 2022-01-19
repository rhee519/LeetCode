class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n) return false;
        unordered_map<char, int> cnt1, cnt2;
        for(int i = 0; i < m; i++) {
            cnt1[s1[i]]++;
            cnt2[s2[i]]++;
        }
        
        for(int i = 0; i+m <= n; i++) {
            // compare s1[0:m-1] & s2[i:i+m-1]
            bool isPermutation = true;
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if(cnt1[ch] != cnt2[ch]) {
                    isPermutation = false;
                    break;
                }
            }
            if(isPermutation) 
                return true;
            cnt2[s2[i]]--;
            if(i+m < n) cnt2[s2[i+m]]++;
        }
        
        return false;
    }
};