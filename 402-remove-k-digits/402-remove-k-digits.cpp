class Solution {
public:
    string removeDigits(string num, int k, int idx) {
        if(k == 0) return num.substr(idx);
        else if(k == num.size()-idx) return "";
        
        // choose min digit of num[idx:idx+k]
        // if min digit == num[j], where idx <= j <= idx+k,
        // then remove num[idx:j-1] -> (j-idx) digits
        // remove as less as possible
        string ans = "";
        char min_digit = num[idx];
        int idx_next = idx;
        for(int i = idx+1; i <= idx+k; i++) {
            if(min_digit > num[i]) {
                min_digit = num[i];
                idx_next = i;
            }
        }
        ans.push_back(min_digit);
        return ans + removeDigits(num, k-(idx_next-idx), idx_next+1);
    }
    
    string removeKdigits(string num, int k) {
        string ans = removeDigits(num, k, 0);
        // get rid of leading zero
        int i = 0;
        while(i < ans.size() and ans[i] == '0') i++;
        return i < ans.size()? ans.substr(i) : "0";
    }
};