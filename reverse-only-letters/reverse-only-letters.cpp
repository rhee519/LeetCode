class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(true) {
            while(left < n && !isalpha(s[left])) left++;
            while(right >= 0 && !isalpha(s[right])) right--;
            if(left >= right) break;
            swap(s[left++], s[right--]);
        }
        
        return s;
    }
};