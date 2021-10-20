class Solution {
public:
    string ltrim(string s) {
        int i = 0;
        while(s[i] == ' ' and i < s.size()) i++;
        return s.substr(i);
    }
    
    string reverseWords(string s) {
        string ans = "";
        
        while((s = ltrim(s)).size()) {
            int idx = s.find(' ');
            if(idx == string::npos) { // no space
                ans = s + " " + ans; break;
            }
            // space exists
            ans = s.substr(0, idx) + " " + ans;
            s = s.substr(idx);
        }
        // remove space at the end of ans
        ans.erase(ans.size()-1, 1);
        return ans;
    }
};