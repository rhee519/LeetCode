bool compare(const string& a, const string& b) {
    return a.length() > b.length();
}

class Solution {
public:
    bool isSubsequence(string str, string sub) {
        int len = str.length(), sublen = sub.length();
        if(len < sublen) return false;
        
        int i = 0, j = 0;
        while(i < len && j < sublen) {
            if(str[i] == sub[j]) j++;
            i++;
        }
        return j == sublen;
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), compare);
        for(string sub: strs) {
            int cnt = 0;
            bool isUncommon = true;
            for(string str: strs) {
                if(isSubsequence(str, sub)) cnt++;
                if(cnt > 1) {
                    isUncommon = false; break;
                }
            }
            if(isUncommon) return sub.length();
        }
        
        return -1;
    }
};